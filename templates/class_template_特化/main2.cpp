/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2019年05月09日 星期四 22时42分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

template<typename T>
struct Hash{
	void operator()(){
		cout << "Hash<T>" << endl;
	}
};

template<>
struct Hash<int>{
	void operator()(){
		cout << "Hash<int>" << endl;
	}	
};

template<>
struct Hash<char>{
	void operator()(){
		cout << "Hash<char>" << endl;
	}
};

int main()
{
	Hash<float> hashfloat;
	hashfloat();

	Hash<int> hashint;
	hashint();

	Hash<char> hashchar;
	hashchar();

	return 0;
}

