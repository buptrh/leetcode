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
        if(nums.size() == 0) {
            return false;
        } else if(nums.size() == 1) {
            return nums[0] == target;
        }
        return helper(nums, target, 0, nums.size()-1);
    }

    bool helper(vector<int> & nums, int target, int start, int end) {
        int mid;
        while(start + 1 < end) {
            // cout<<start<<end<<endl;
            mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                if(nums[start] < nums[mid]) {
                    if(nums[start] == target) {
                        return true;
                    } else if(nums[start] > target) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                } else if(nums[start] > nums[mid]) {
                    end = mid;
                } else {
                    return helper(nums, target, start, mid - 1) || helper(nums, target, mid + 1, end);
                }
            } else if(nums[mid] < target) {
                if(nums[start] < nums[mid]) {
                    start = mid + 1;
                } else if(nums[start] > nums[mid]) {
                    if(nums[start] == target) {
                        return true;
                    } else if(nums[start] < target) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                } else {
                    return helper(nums, target, start, mid - 1) || helper(nums, target, mid + 1, end);
                }
            } else {
                return helper(nums, target, start, mid-1) || helper(nums, target, mid+1, end);
            }
        }
        return (nums[start] == target || nums[end] == target);
    }

};