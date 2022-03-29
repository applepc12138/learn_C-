/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年10月24日 星期六 12时47分26秒
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

function<void(int a, int b)> func()
{
	int ss = 520;
	return [ss](int, int)mutable{
		cout << ++ss;
	};
}

int main()
{
	auto f = func();
	f(1, 3);
	return 0;
}
