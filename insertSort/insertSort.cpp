#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums);
int main()
{
	vector<int> nums{12151,542,45,562,212,12,412,22,5625,66666,212};
	insertSort(nums);
	for(auto &p : nums)
		cout << p << "  ";	
	return 0;
}

void insertSort(vector<int> &nums){
	for( unsigned int i = 1; i < nums.size(); ++i){
		int temp = nums[i];
		for( int j = i - 1; j >= 0; --j){
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










