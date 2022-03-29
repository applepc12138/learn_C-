/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2021年03月17日 星期三 14时43分54秒
 ************************************************************************/

#include <iostream>
using namespace std;

class base
{
	public:
	static base *get_instance();
	void output();	
	private:
		base();
		int a;
		char c;
};
base *base::get_instance()
{
	static base instance;
	return &instance;
}
void base::output()
{
	cout << a << "  " << c << endl;
}
base::base():a(33),c('9')
{

}
int main()
{
	base::get_instance()->output();
	return 0;
}
