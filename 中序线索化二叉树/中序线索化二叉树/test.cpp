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
	//�ⲻ�ǵ����޲ҹ��캯������ʽ�������޲ҹ��캯����������ʽ Teacher T;
   // Teacher T2();   //�������ᷢ������  T2.show();��һ����������

	system("pause");
}