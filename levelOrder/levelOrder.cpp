/*************************************************************************
	> File Name: levelOrder.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2019年12月16日 星期一 22时51分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node{
	int data;	
	Node *root;
	Node *left;
	Node *right;
}TreeNode;

int main(){

	return 0;
}
	int numberOfloor(TreeNode* root, int k){
        int i = -1, j = -1; //i指向队头元素，j指向队尾元素之后
        int floor = 0;
        int flag = 0;   //标记当前层最后一个元素
        TreeNode* q[500];
        q[++i] = root;
        j = 1;
        while(i < j){
            if(i == flag){
                flag = j;
                ++floor;
            }
            TreeNode* p = q[i++];
            if(p -> left)
                q[j++] = p -> left;
            if(p -> right)
                q[j++] = p -> right;

        }
        return floor;
    }






   int numberOfloor(TreeNode* root, int k){
        int i = -1, j = -1; //i指向队头元素，j指向队尾元素之后
        int floor = 0;
        int first = 0;  //
        int last = 0;   //标记当前层最后一个元素
        TreeNode* q[500];
        q[++i] = root;
        j = 1;
        while(i < j){
            if(i == last){
                ++floor;
                first = last;
                last = j;
                if(floor == k)
                    return last - first;
            }
            TreeNode* p = q[i++];
            if(p -> left)
                q[j++] = p -> left;
            if(p -> right)
                q[j++] = p -> right;

        }
        return 0;
    }

