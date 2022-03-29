#include <iostream>
#include <vector>
#include <ctime>

#define COUNT 50

using namespace std;

void shellSort(vector<int> &nums);
void insertSort(vector<int> &nums);
void selectSort(vector<int> &nums);
void quickSort(vector<int> &nums, int l, int r);
int partSort(vector<int> &array, int left, int right);
void heapSort(vector<int> &nums);
void siftDown(vector<int> &nums, int l, int r);

int main()
{
	vector<int> nums{255,41,525,6,25,35,421,6,25,36,15,22,51,212,20,2,35,26666,552};
	

	srand((unsigned)time(NULL));
	for(int cnt = 0; cnt < COUNT; ++cnt)
		nums.push_back(rand() % (COUNT * 2));
	vector<int> nums1 = nums, nums2 = nums, nums3 = nums,nums4 = nums;
	
	time_t start3 = clock();
	quickSort(nums3, 0, nums3.size());
	time_t end3 = clock();
	cout << "quicksort time: " << difftime(end3, start3) << "ms" << endl; 
	
	time_t start = clock();
	shellSort(nums);
	time_t end = clock();
	cout << "shellsort time: " << difftime(end, start) << "ms" << endl; 

	time_t start4 = clock();
	heapSort(nums4); 
	time_t end4 = clock();
	cout << "heapsort time: " << difftime(end4, start4) << "ms" << endl; 

	for(auto &p : nums4)
		cout << p << "  ";
	cout << endl;
	
	time_t start2 = clock();
	//insertSort(nums2);
	time_t end2 = clock();
	cout << "insertsort time: " << difftime(end2, start2) << "ms" << endl; 
	
	time_t start1 = clock();
	//selectSort(nums1);
	time_t end1 = clock();
	cout << "selecetsort time: " << difftime(end1, start1) << "ms" << endl; 

	

	return 0;
}

void shellSort(vector<int> &nums){
	int gap = nums.size();
	while(gap > 1){
		gap = gap / 3 + 1;
		for(int i = 0; i < gap; ++i){//对于每一个分组
			for(int j = i + gap; j < nums.size(); j += gap){
				int temp = nums[j];//对于每一个要被插入的数
				for(int k = j - gap; k >= i; k -= gap){
					if(temp < nums[k]){
						nums[k + gap] = nums[k];
						if(k == i)
							nums[k] = temp;
					}else{
						nums[k + gap] = temp;
						break;
					}
				}
			}
		}
	}

}

void insertSort(vector<int> &nums){
	for(int i = 1; i < nums.size(); ++i){
		int temp = nums[i];
		for(int j = i - 1; j >= 0; --j){
			if(temp < nums[j]){
				nums[j + 1] = nums[j];
				if(j == 0)
					nums[0] = temp;
			}else{
				nums[j + 1] = temp;
				break;
			}
		}
	}

}

void selectSort(vector<int> &nums){
	for(int i = 0; i < nums.size(); ++i){
		for(int j = i + 1; j < nums.size(); ++j){
			if(nums[i] > nums[j])
				swap(nums[i], nums[j]);
		}
	}
}

void quickSort(vector<int> &nums, int l, int r){
	if(l < r){
		int q = partSort(nums, l, r);
		quickSort(nums, l, q - 1);
		quickSort(nums, q + 1, r);
	}
}

int partSort(vector<int> &array, int left, int right){
	int &key = array[left];
	while(left != right){
		while(left < right && array[right] >= key)
			--right;
		while(left < right && array[left] <= key)
			++left;
		swap(array[left], array[right]);
	}
	swap(array[left], key);
	return left;
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

void siftDown(vector<int> &nums, int l, int r){
	while(true){
		// 当列表第一个是以下标0开始，结点下标为i,左孩子则为2*i+1,右孩子下标则为2*i+2;
		// 若下标以1开始，左孩子则为2*i,右孩子则为2*i+１
		int leftChild = 2 * l + 1;// 左孩子的结点下标
		// 当结点的右孩子存在，且大于结点的左孩子时
		if(leftChild > r)
			break;
		if(leftChild + 1 <= r && nums[leftChild + 1] > nums[leftChild])
			++leftChild;	

		if(nums[leftChild] > nums[l]){// 当左右孩子的最大值大于父结点时，则交换
			swap(nums[leftChild], nums[l]);
			l = leftChild;// 交换之后以交换子结点为根的堆可能不是大顶堆，需重新调整
		}else// 若父结点大于左右孩子
			break;
	}	
}

