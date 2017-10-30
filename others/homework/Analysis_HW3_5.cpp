
#include <iostream>
#include <vector>
using namespace std;

int minumunSubarray(vector<int> & nums) {
	int currentPos = -1;
	int mostRight = 0;
	int ret = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] > 0) {
			int sum = 0;
			int j = i;
			for(; j < nums.size(); j++) {
				sum += nums[j];
			}
			while(sum <= 0 && j >= mostRight) {
				j--;
				sum -= nums[j];
			}
			if(sum > 0) {
				mostRight = max(mostRight, j-1);
			}

			if(i > currentPos) {
				currentPos = mostRight;
				ret ++;
			}
		}
	}
	return ret;
}

int main() {
	vector<int> nums{-5, -6, -7, 3, -5, 7, -4, 1, -8, 3, -7, 5, -9, 5, -200, 4, -2, -3};
	cout<<minumunSubarray(nums);
}