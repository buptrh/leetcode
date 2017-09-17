#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool twoSums(vector<int> nums) {
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size()-1;
	while(left < right) {
		int sum = nums[left] + nums[right];
		if(sum == 0) {
		cout<< nums[left] << "  " << nums[right] << endl;
			return true;
		} else if(sum < 0) {
			left++;
		} else {
			right--;
		}
	}
	return false;
}