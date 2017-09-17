class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        if(nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        return helper(nums, target, 0, nums.size()-1);
    }

    int helper(vector<int>& nums, int target, int start, int end) {
        if(start + 1 >= end) {
            if(nums[start] == target) {
                return start;
            } else if(nums[end] == target) {
                return end;
            } else {
                return -1;
            }
        }
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            if(nums[start] < nums[mid] || nums[start] > target) {
                return helper(nums, target, mid, end);
            } else {
                return helper(nums, target, start, mid);
            }
        } else {
            if(nums[start] > nums[mid] || nums[start] <= target) {
                return helper(nums, target, start, mid);
            } else {
                return helper(nums, target, mid, end);
            }
        }
    }
};