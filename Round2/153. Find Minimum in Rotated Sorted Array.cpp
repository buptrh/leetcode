class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid;
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(nums[mid] < nums[start]) {
                end = mid;
            } else if(nums[start] < nums[end]) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }
        if(nums[start] < nums[end]) {
            return nums[start];
        } else {
            return nums[end];
        }
    }
};