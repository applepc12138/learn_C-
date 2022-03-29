/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年12月05日 星期六 14时51分28秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Base1{
	virtual void base1_foo(){
		cout << "Base1::base1_foo called" << endl;
	}
	virtual void base1_foo2(){
		cout << "Base1::base1_foo2 called" << endl;
	}
	int Base1_a =320;
};

struct Base2{
	virtual void base2_foo(){
		cout << "Base2::base2_foo2 called" << endl;
	}
	int Base2_a = 3333;
	char Base2_c = 'm';
};

struct Der1 : public Base1, public Base2{
	void base1_foo2() override{
		cout << "Der1::base1_foo2 called" << endl;
	}
	virtual void Der1_foo(){
		cout << "Der1::Der1_foo called" << endl;
	}
	int Der1_i = 2222;
	char Der1_c = 'c';
};

int main()
{
	cout << "Base1 size = " << sizeof(Base1) << endl;
	cout << "Base2 size = " << sizeof(Base2) << endl;
	cout << "Der1 size = " << sizeof(Der1) << endl;


	return 0;
}
