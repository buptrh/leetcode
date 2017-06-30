class Solution {
public:
    int findMin(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }

    int solve(std::vector<int>& nums, int start, int end) {
    	int mid = (start+end)/2;
    	if(start == end) {
    		return nums[start];
    	}
    	else if(nums[start] < nums[end]) {
    		return nums[start];
    	} else if(nums[end] < nums[mid]) {
    		return solve(nums, mid+1, end);
    	} else {
    		return solve(nums, start, mid);
    	}
    }
};