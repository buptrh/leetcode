class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	if(nums.size() == 0) {
    		return -1;
    	} else if(nums.size() == 1) {
    		return 0;
    	}
        int start = 0, end = nums.size() - 1, mid;
        while(start + 1 < end) {
        	mid = start + (end - start) / 2;
        	if(nums[mid] > nums[mid+1]) {
        		end = mid;
        	} else if(nums[mid] < nums[mid+1]) {
        		start = mid;
        	} else {

        	}
        }

        if(nums[start] < nums[end]) {
        	return end;
        } else if(nums[start] > nums[end] ) {
        	return start;
        }
        return -1;

    }
};