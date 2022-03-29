/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年10月23日 星期五 15时26分04秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

bool islonger(const string &s, size_t size = 6)
{
	return s.size() > size;
}

int main(int argc, char *argv[])
{
	vector<string> vec{"hello", "linux", "ggboypc12138", 
	"fuccccccccccccccck"};
	auto iter = find_if(vec.begin(), vec.end(), 
			[size = 6](const string &s){//c++14
			return s.size() > size;
		});
	cout << *iter << endl;
	/* iter = find_if(vec.begin(), vec.end(),  */
	//     islonger);
	// cout << *iter << endl;
	using namespace std::placeholders;
	auto func = bind(islonger, _1, 6);
	iter = find_if(vec.begin(), vec.end(),
			func);
	cout << *iter << endl;

	string s{"hehehehhe"};
	auto f = bind(islonger, s, 5);
	
	cout << f() << endl;

	auto ss = new string{"hehehheheheh"};
	auto ff = bind(islonger, *ss, 6);
	cout << ff() <<endl;
	delete ss;

	return 0;
}
