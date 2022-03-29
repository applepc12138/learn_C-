/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年10月27日 星期二 16时12分42秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main()
{
	string &&rref = string("haha");
	string &lref = rref;
	cout << lref << endl;
	lref[0] = 'p';
	cout << lref << endl;
	return 0;
}
