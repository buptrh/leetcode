class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size());
    }

    int solve(vector<int> & nums, int target, int start, int end) {
    	if(end <= start) {
    		return start;
    	}
    	int mid = (start + end)/2;
    	if(nums[mid] == target) {
    		return mid;
    	} else if(nums[mid] > target) {
    		return solve(nums, target, start, mid);
    	} else {
    		return solve(nums, target, mid+1, end);
    	}

    }
};