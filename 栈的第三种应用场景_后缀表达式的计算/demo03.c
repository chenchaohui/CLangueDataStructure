#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

//判断字符c是否是一个数字
int isDigital(char c)
{
	return (c>='0' && c<='9');
}

//判断字符是不是一个运算符,这里只列举了+ - * /四种运算符当染是可以增加及其运算符的
int isOperator(char c)
{
	return (c =='+' ||c =='-' ||c =='*' ||c =='/' );
}

//数字类型的字符转化成真正的数字
int value(char c)
{
	return (c - '0');
	//return (c-48);
}
//针对运算符做的操作《计算》
int express(int left, int right, char op)
{
	int ret = 0;

	switch(op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}

int compute(const char* exp)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while( exp[i] != '\0' )
	{
		if( isDigital(exp[i]) )
		{
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if( isOperator(exp[i]) )
		{
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left, right, exp[i]);

			LinkStack_Push(stack, (void*)result);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}
		i++;
	}

	if( (LinkStack_Size(stack) == 1) && (exp[i] == '\0') )
	{
		ret = (int)LinkStack_Pop(stack);
	} 
	else 
	{
		printf("Invalid expression!");
	}

	LinkStack_Destroy(stack);

	return ret;
}

void main()
{
	printf("8 + (3 - 1) * 5  = %d\n", compute("831-5*+"));
	system("pause");

}