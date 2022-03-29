/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2020年10月19日 星期一 17时09分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

class base1{
	public:
		virtual void print(){
			cout << "base1" << endl;
		}
	private:
		int b1;
};

class base2{
	public:
		virtual void ouput(){
			cout << "base2" << endl;
		}	
	private:
		int b2;
};

class sub:public base1,public base2{
	public:
	void print(){
		cout << "sus" << endl;
	}	
	private:
		int s1;
};


int main()
{
	base1 *b1 = new sub();
	base2 *b2 = (base2 *)b1;
	printf("b1 = %p\nb2 = %p\n", b1, b2);
	return 0;
}
