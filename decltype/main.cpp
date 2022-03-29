/*************************************************************************
	> File Name: mian.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年10月23日 星期五 20时33分31秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T, typename ...ARG>
decltype(auto) test(T&& func, ARG ...arg)
{
	std::cout << sizeof(decltype(func(arg...))) << std::endl; 
	return func(arg...);
}

int main(int argc, char *argv[])
{
	std::vector<std::string> vec{"hello", "world", "linux", "fuccccccck", "main.cpp"};
	auto p = test(
			[](const std::vector<std::string> v, size_t size){
				return std::find_if(v.begin(), v.end(), [size](const std::string &s){return s.size() > size;});			
			},
			vec,
			6
			);
	std::cout << *p << std::endl;
	return 0;
}
