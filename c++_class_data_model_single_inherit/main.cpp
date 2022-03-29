/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年12月05日 星期六 12时36分23秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Base1{
	virtual void foo(){
		cout << "Base1::foo called" << endl;
	}
	virtual void foo2(){
		cout << "Base1::foo2 called" << endl;
	}
	int a = 520;
	
};

struct Der1 : public Base1{
	int i = 1;
	virtual void foo2(){
		cout << "覆盖基类Base1::foo2" << endl;
	}
	virtual void der_foo(){
		cout << "Der1::der_foo called" << endl;
	}
};

int main(int argc, char *argv[])
{
	printf("Base1 size = %d\n", sizeof(Base1));
	printf("Der1 size = %d\n", sizeof(Der1));
	printf("Base1::a offset %p\n", &Base1::a);
	printf("Base1::foo offset %p\n", &Base1::foo);

	Base1 b1;
	typedef void(*Funptr)(void);
	cout << "通过地址调用Base1::虚函数" << endl;
	long *vptr = (long *)*((long *)(&b1));
	Funptr fun = (Funptr)vptr[0];
	Funptr fun2 = (Funptr)vptr[1];
	(*fun)();
	fun2();

	cout << "通过地址调用Der1::虚函数" << endl;
	Der1 d1;
	long *Dvptr = (long *)*((long *)(&d1));
	Funptr Dfun = (Funptr)Dvptr[0];
	Funptr Dfun2 = (Funptr)Dvptr[1];
	Funptr Dfun3 = (Funptr)Dvptr[2];
	Dfun();
	Dfun2();
	Dfun3();
	

	return 0;
}
