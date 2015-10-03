#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
//��д�ø���������һ��������
//�ж��ַ�c�Ƿ���һ������
int isDigital(char c)
{
	return (c>='0' && c<='9');
}

//�ж��ַ��ǲ���һ�������,����ֻ�о���+ - * /�����������Ⱦ�ǿ������Ӽ����������
int isOperator(char c)
{
  return (c =='+' ||c =='-' ||c =='*' ||c =='/' );
}

//�ж��Ƿ���������
int isLeft(char c)
{
   return (c == '(');
  
}

//�ж��Ƿ���������
int isRight(char c)
{
  return (c == ')');
}

//�ж�����������ȼ�
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

//����ַ�
void outPut(char c)
{
  if(c != '\0')
  {
    printf("%c ",c);
  }
}

//<���Ĵ���>��׺���ʽת��׺���ʽ
//�������������ʹ���һ��������ת����char ---> int ---> void * --->int ---->char��������ת���ǲ������������������ģ�ԭ����խ����������ת��Ϊ����������͡�
void transForm(const char* exp)
{
  int i = 0;
  //����һ������
  LinkStack *stack = LinkStack_Create();
  while(exp[i] != '\0')
  {
   if (isDigital(exp[i]))
   {
	  outPut(exp[i]);
   }

   else if (isOperator(exp[i]))
   {
     //��ȡջ��Ԫ��
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
	   //�����ų�ջ
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

