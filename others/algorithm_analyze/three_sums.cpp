#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool threeSums(vector<int> nums) {
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++) {
		int left = i+1, right = nums.size()-1;
		while(left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if(sum == 0) {
			cout<< nums[i] << "  " << nums[left] << "  " << nums[right] << endl;
				return true;
			} else if(sum < 0) {
				left++;
			} else {
				right--;
			}
		}
	}
	return false;
}