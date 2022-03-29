/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年01月26日 星期日 10时33分01秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec{1,12,55,3,56,25,250,520,4,0,1314};
	for(int i = 0; i < 10; ++i)
		*back_inserter(vec)  = i;
	for(auto& p : vec)
		cout << p << "  ";
	return 0;
}
