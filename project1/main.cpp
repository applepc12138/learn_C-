#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> vec{"hello","this","is","linux"};
	for(auto &p : vec){
		cout << p << "  " << ends;
	}
	cout << endl;
	cout << "this is first linux c++ project!" << endl;
	vector<int> nums{123, 2, 4, 55, 56, 76, -52, 444};
	int sum = 0; 
	for(auto &p : nums){
		sum += p;
	}
	for(int i = 0; i < 5; i++){
	}
	cout << "sum = " << sum << endl;
	return 0;
	cout << endl;
}

