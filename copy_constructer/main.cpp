/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年01月30日 星期四 17时59分52秒
 ************************************************************************/

#include<iostream>
#include <memory>

using namespace std;

class str {
public:
	string * ptr;
	int i;
public:
	//默认构造函数
	str(const string &_s = "") :ptr(new string(_s)), i(0) {
		cout << "调用形参为“const string&”(默认)构造函数" << endl;
	}
	str(const char*p) :ptr(new string(p)), i(0){
		cout << "调用形参为“const char*”的构造函数" << endl;
	}
	//拷贝构造函数
	str(const str &_str) :ptr(new string(*_str.ptr)), i(_str.i) {
		cout << "调用拷贝构造函数" << endl;
	}
	//移动构造函数
	str(str &&_str) :ptr(_str.ptr), i(_str.i) { _str.ptr = nullptr, _str.i = 0; }
	//析构函数
	~str() { delete ptr; }
};

void ff(str s);
str gg();
str dd();

int main()
{
	str s1;
	str s2("dd");	
	str s3 = s1;
	str s4 = string("ff");
	str s5 = " ddd dd ";
	ff("ddd");
	ff(s5);
	gg();
	dd();
	return 0;
}

void ff(str s){

}

str gg(){
	return "aaaa";
}

str dd(){
	return string("dddd");
}
