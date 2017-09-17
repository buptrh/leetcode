class Solution {
public:
    int findMin(vector<int>& nums) {
    	return helper(nums, 0, nums.size() - 1);
    }
       
    int helper(vector<int>& nums, int start, int end) {
    	if(start + 1 >= end) {
    		return min(nums[start], nums[end]);
    	}

    	int mid = start + (end - start) / 2;
    	if(nums[start] < nums[end]) {
    		return nums[start];
    	}

    	if(nums[start] < nums[mid]) {
    		return helper(nums, mid+1, end);
    	} else if(nums[start] == nums[mid]) {
    		return helper(nums, start+1, end);
    	} else {
    		return helper(nums, start, mid);
    	}
    }
};