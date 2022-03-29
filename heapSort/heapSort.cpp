/*************************************************************************
	> File Name: heapSort.cpp
	> Author: ggboypc12138
	> Mail: lc1030244043@outlook.com 
	> Created Time: 2019年04月20日 星期六 18时35分03秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#define COUNT 500
using namespace std;


void heapSort(vector<int> &nums);
void siftDown(vector<int> &nums, int l, int len);

int main()
{
	vector<int> nums{16, 7, 3, 20, 17, 8, 434, 4,-56,6,777, 1314, 250 ,520, -111, 21, -5};
	srand((unsigned)time(NULL));
	for(int cnt = 0; cnt < COUNT; ++cnt)
		nums.push_back(rand() % (COUNT * 2));
	heapSort(nums);
	int i = 0;
	for(auto &p : nums){
		cout << p << "  ";
		++i;
		if(i == 25){
			i = 0; 
			cout << endl;
		}
	}
	return 0;
}

void heapSort(vector<int> &nums){
	// 首先初始化大顶堆
	int first = nums.size() / 2 - 1;// 最后一个有孩子的节点

	for(int i = first; i > -1; --i){ // 第一个结点的下标为０,从最后一个有孩子的节点开始往上调整
		siftDown(nums, i, nums.size() - 1);// 初始化大顶堆
	}
	for(int j = nums.size() - 1; j > 0; --j){
		swap(nums[j], nums[0]);// 交换堆顶与堆尾
		siftDown(nums, 0, j - 1);// 堆长度减一，再从上往下调整成大顶堆
	}
}

/*******************************************************************************************
	初始化大顶堆时 是从最后一个有子节点开始往上调整最大堆。而堆顶元素(最大数)与堆最后一个数交换后，需再次调整成大顶堆，此时是从上往下调整的。
	不管是初始大顶堆的从下往上调整，还是堆顶堆尾元素交换，每次调整都是从父节点、左孩子节点、右孩子节点三者中选择最大者跟父节点进行交换，交换之后都可能造成被交换的孩子节点不满足堆的性质，因此每次交换之后要重新对被交换的孩子节点进行调整。
*******************************************************************************************/

void siftDown(vector<int> &nums, int l, int len){
	while(true){
		// 当列表第一个是以下标0开始，结点下标为i,左孩子则为2*i+1,右孩子下标则为2*i+2;
		// 若下标以1开始，左孩子则为2*i,右孩子则为2*i+１
		int leftChild = 2 * l + 1;// 左孩子的结点下标
		// 当结点的右孩子存在，且大于结点的左孩子时
		if(leftChild > len)
			break;
		if(leftChild + 1 <= len && nums[leftChild + 1] > nums[leftChild])
			++leftChild;	

		if(nums[leftChild] > nums[l]){// 当左右孩子的最大值大于父结点时，则交换
			swap(nums[leftChild], nums[l]);
			l = leftChild;// 交换之后以交换子结点为根的堆可能不是大顶堆，需重新调整
		}else// 若父结点大于左右孩子
			break;
	}	
}

