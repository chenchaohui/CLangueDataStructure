#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
//提醒一下C语言中不含bool数据类型
int isLeft( char c)
{
	int ret = 0;
	switch (c)
	{
	case '<':
	case '[':
	case '{':
	case '(':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int isRight( char c)
{
	int ret = 0;
	switch (c)
	{
	case '>':
	case ']':
	case '}':
	case ')':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

int match( char left, char right)
{ 
	int ret = 0;
	switch(left)
	{
	case '<' :
		ret = (right == '>');
		break;
	case '[' :
		ret = (right == ']');
		break;
	case '{' :
		ret = (right == '}');
		break;
	case '(' :
		ret = (right == ')');
		break;
	case '\'' :
		ret = (right == '\'');
		break;
	case '\"' :
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}


int scanner(const char *str /*in*/)   //主调函数分配内存空间
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (isLeft(str[i]))
		{
			LinkStack_Push(stack,(void *)(str+i));
		}
		if (isRight(str[i]))
		{
			char *c =  (char *)LinkStack_Pop(stack);
			if (c == NULL || !match(*c,str[i]))
			{
				printf("%c does not match!\n", str[i]);
				ret = 0;
				break;
			}	  
		}
		i++;
	}

	if (str[i] == '\0' && LinkStack_Size(stack) == 0)
	{
		printf("match succeed\n");
		ret = 1;
	}
	else
	{
		printf("Invalid code!\n");
		ret = 0;
	}
	LinkStack_Destroy(stack);
	return ret;
}

void main()
{
	const char* str = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0; ";
	scanner(str);
	system("pause");
	return ;
}

