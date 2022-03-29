/*************************************************************************
	> File Name: main.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2019年05月05日 星期日 22时34分57秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		Node *l, *r;
	public:
		Node(int value){
			data = value;
			l = r = nullptr;
		}
};
typedef Node* Tree;

void insert(Tree &T, int value);
Tree creatTree(vector<int> &nums);
void firstOrder(Tree T);
void middleOrder(Tree T);
void floorOrder(Tree T);
vector<int> levelOrder(Tree root);

int main()
{
	vector<int> nums{3,5,1,6,7,2,33,12,54,23,16,29,150,520,13,14,520,122};
	cout << "nums:  ";
	for(auto &p : nums)
		cout << p << " ";
	cout << endl;
	auto t = creatTree(nums);	
	firstOrder(t);
	cout << endl;
	middleOrder(t);
	cout << endl;
	floorOrder(t);
	return 0;
}

void insert(Tree &T, int value){
	if(T == nullptr){
		T = new Node(value);
	}
	else if(T->data < value){
		insert(T->r, value);	
	}else if(T->data > value){
		insert(T->l, value);	
	}
}

Tree creatTree(vector<int> &nums){
	Tree T = new Node(nums[0]);
	for(unsigned int i = 1; i < nums.size(); ++i){
		insert(T, nums[i]);		
	}
	return T;
}

void firstOrder(Tree T){
	if(T != nullptr){
		cout << T->data << "  ";
		firstOrder(T->l);
		firstOrder(T->r);
	}	
}

void middleOrder(Tree T){
	if(T != nullptr){
		firstOrder(T->l);
		cout << T->data << "  ";
		firstOrder(T->r);
	}	
}

//层序遍历
void floorOrder(Tree T){
	queue<Tree> q;
	if(T != nullptr)
		q.push(T);
	while(!q.empty()){
		cout << q.front()->data << "  ";
		if(q.front()->l != nullptr)
			q.push(q.front()->l);
		if(q.front()->r != nullptr)
			q.push(q.front()->r);
		q.pop();
	}
}

vector<int> levelOrder(Tree root){
	vector<int> ret;
	queue<Tree> q;
	if(root)
		q.push(root);
	while(!q.empty()){
		Tree temp = q.front();
		ret.push_back(temp->data);
		q.pop();
		if(temp->l)
			q.push(temp->l);
		if(temp->r)
			q.push(temp->r);
	}
	return ret;
}

/*--------------------- 
作者：ColiYin 
来源：CSDN 
原文：https://blog.csdn.net/sinat_20177327/article/details/78285495 
-----------------------*/
