/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年12月03日 星期四 21时43分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct base{};
struct Der1  : base{};

struct  Der2  :  base{
	int  i;
};

struct Base1{
	int i;
};

struct Base2{
	int i;
	virtual void foo(){
	}
};

struct D:Base1{
	int j;
};

struct D1:Base2{
	int j;
};

struct D2:Base1{
	int j;
	virtual void fooOfD2(){
	}
};

struct D3:Base2{
	int j;
	virtual void fooOfD3(){
	}
};

struct Base3{
	public:
		virtual void foo(){
			cout << "Base3::foo() called" << endl;
		}
		virtual void foo2(){
			cout << "Base3::foo2() called" << endl;
		}
	//private:
		static int si;
		float x = 520;
		float y = 250;
		float z = 666;
};

int main()
{
	cout  << "base size = " << sizeof(base) << endl;//1
	cout  << "Der1 size = " << sizeof(Der1) << endl;//1
	cout  << "Der2 size = " << sizeof(Der2) << endl;//4

	cout << "Base1 size = " << sizeof(Base1) << endl;//4
	cout << "Base2 size = " << sizeof(Base2) << endl;//16
	cout << "D size = " << sizeof(D) << endl;//8
	cout << "D1 size = " << sizeof(D1) << endl;//16
	cout << "D2 size = " << sizeof(D2) << endl;//16
	cout << "D3 size = " << sizeof(D3) << endl;//16
	
	cout << "Base3::x offset = " << &Base3::x << endl;//1
	cout << "Base3::y offset = " << &Base3::y << endl;//1
	cout << "Base3::z offset = " << &Base3::z << endl;//1
	cout << "float size = " << sizeof(float) << endl;//4
	cout << "成员变量在Base3中的偏移量:" << endl;
	printf("Base3::x offset = %p\n", &Base3::x);//0x8
	printf("Base3::y offset = %p\n", &Base3::y);//0xc
	printf("Base3::z offset = %p\n", &Base3::z);//0x10
	
	Base3 base3;
	printf("base3 addr = %p\n", &base3);
	printf("base3 vptr = %p\n", (void *)*((long *)&base3));
	printf("base3::foo %p\n", &Base3::foo);//0x1
	printf("base3::foo2 %p\n", &Base3::foo2);//0x9

	typedef void(*Funptr)(void);
	cout << "通过地址，调用虚函数Base3::foo" << endl;
	Funptr funptr = (Funptr)((*((long *)*(long *)(&base3))));
	funptr();
	
	cout << "通过地址，调用虚函数Base3::foo2" << endl;
	Funptr funptr2 = (Funptr)((*(((long *)*(long *)(&base3)) + 1)));
	funptr2();
	
	
	return 0;
}
