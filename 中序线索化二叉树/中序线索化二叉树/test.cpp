#include<iostream>
using namespace std;
class Teacher
{
private:
	int age;
public:
	Teacher(){}
	Teacher(int a):age(a){}
public:
	~Teacher(){}
public:
	void show()
	{
		printf("%d\n",this->age);
	}
};


void main02()
{
	Teacher T1(10);
	T1.show();


	int *p = NULL;

	int **pp = &p;
	//这不是调用无惨构造函数的形式，调用无惨构造函数的真正形式 Teacher T;
   // Teacher T2();   //编译器会发出警告  T2.show();是一个错误的语句

	system("pause");
}