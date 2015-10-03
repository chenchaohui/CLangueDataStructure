#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
//先写好各个函数的一个整体框架
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

//判断是否是左括号
int isLeft(char c)
{
   return (c == '(');
  
}

//判断是否是右括号
int isRight(char c)
{
  return (c == ')');
}

//判断运算符的优先级
int priority(char c)
{
   int ret = 0;
   if ((c == '+') ||(c =='-'))
   {
	   ret = 1;
   }
   if( (c == '*') || (c == '/'))
   {
	   ret = 2;
   }
   return ret;
}

//输出字符
void outPut(char c)
{
  if(c != '\0')
  {
    printf("%c ",c);
  }
}

//<核心代码>中缀表达式转后缀表达式
//程序中数据类型存在一个这样的转换：char ---> int ---> void * --->int ---->char；这样的转换是不存在数据溢出的情况的，原因是窄的数据类型转换为宽的数据类型。
void transForm(const char* exp)
{
  int i = 0;
  //创建一个链表
  LinkStack *stack = LinkStack_Create();
  while(exp[i] != '\0')
  {
   if (isDigital(exp[i]))
   {
	  outPut(exp[i]);
   }

   else if (isOperator(exp[i]))
   {
     //获取栈顶元素
	   if ( LinkStack_Size(stack)>0 )
	   {
		   while ( LinkStack_Size(stack)>0 && priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)) )
		   {		 
			   outPut((char)(int)LinkStack_Pop(stack));
		   }
	   }
	 
	  LinkStack_Push(stack,(void *)(int)exp[i]);
   }

   else if (isLeft(exp[i]))
   {
      LinkStack_Push(stack,(void *)(int)exp[i]);
   }

   else if (isRight(exp[i]))
   {
	   while (!isLeft((char)(int)LinkStack_Top(stack)))
	   {
		    outPut((char)(int)LinkStack_Pop(stack));
	   }
	   //左括号出栈
	   LinkStack_Pop(stack);
   }

   else
   {
      printf("Invalid expression\n");
	  break;
   }
   i++;
  }

  while ( exp[i]=='\0' && LinkStack_Size(stack)>0)
  {
	  outPut((char)(int)LinkStack_Pop(stack));
  }
  LinkStack_Destroy(stack);
}

void main()
{

	transForm("8+(3-1)*5");
	printf("\n");
	system("pause");
	return ;
}

