/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2019年05月08日 星期三 22时55分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<deque>

using namespace std;


template<typename T>
T max(const T&a, const T&b);

template<typename T>
T max(const T&a, const T&b){
	return a > b ? a : b;
}

string max(const string &a, const string &b){
	cout << "call special max function" << endl;
	return a > b ? a : b;
}

template<typename T, typename CONT = vector<T>>

class Stack{
		CONT nums;
	public:
		void push(const T& value);
		T top() const;
		bool empty() const;
		T pop();
};


int main()
{	
	cout << "max : " << ::max(43, 233) << endl; 
	string str1("hello"), str2("hi world!");
	cout << "max : " << ::max(str1, str2) << endl; 
	Stack<int, list<int> > S;
	S.push(520);
	cout << S.pop() << endl;
	return 0;
}

template<typename T, typename CONT> 
void Stack<T,CONT>::push(const T& value){
	nums.push_back(value);
}

template<typename T, typename CONT>
T Stack<T,CONT>::top() const{
	if(!empty())
		return nums.back();
}

template<typename T, typename CONT>
bool Stack<T,CONT>::empty() const{
	return nums.empty();
}

template<typename T, typename CONT>
T Stack<T,CONT>::pop(){
	if(!empty()){
		auto temp = nums.back(); 
		nums.pop_back();
		return temp;
	}
	return 0;
}
