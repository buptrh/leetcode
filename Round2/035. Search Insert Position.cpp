class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size() == 0) {
    		return 0;
    	}
        int start = 0, end = nums.size()-1, mid;
        while(start + 1 < end) {
        	mid = start + (end - start) / 2;
        	if(nums[mid] == target) {
        		return mid;
        	} else if(nums[mid] < target) {
        		start = mid;
        	} else {
        		end = mid;
        	}
        }
        if(nums[start] >= target) {
        	return start;
        } else if(nums[end] >= target) {
        	return end;
        } else {
        	return end + 1;
        }
    }
};