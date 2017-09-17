// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Write a function to determine if a given target is in the array.

// The array may contain duplicates.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	return solve(nums, target, 0, nums.size()-1);
    }

    bool solve(vector<int>& nums, int target, int start, int end) {
        int mid = 0;
        bool ret = false;
        // cout<< start << end << endl;
        if(start <= end) {
        	mid = start + (end - start) / 2;
        	if(nums[mid] == target) {
        		return true;
        	} else if(nums[mid] == nums[start]) {
        		ret = solve(nums, target, start+1, end);
        	} else if(nums[mid] < target) {
	        	if(nums[start] > nums[mid]){
	        		if(nums[start] == target) {
	        			return true;
	        		} else if(nums[start] < target) {
	        			ret = solve(nums, target, start, mid - 1);
	        		} else {
	        			ret = solve(nums, target, mid + 1, end);
	        		}
	        	} else {
        			ret = solve(nums, target, mid + 1, end);
	        	}
        		if(ret) {
        			return true;
        		}
        	} else {
	        	if(nums[start] <= nums[mid]){
	        		if(nums[start] == target) {
	        			return true;
	        		} else if(nums[start] < target) {
	        			ret = solve(nums, target, start, mid - 1);
	        		} else {
	        			ret = solve(nums, target, mid + 1, end);
	        		}
	        	} else {
        			ret = solve(nums, target, start, mid - 1);
	        	}
        		if(ret) {
        			return true;
        		}
        	}
        }
        return ret;
    }
};