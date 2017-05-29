class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size()-1, k);
    }

	int quickSort(vector<int>& nums, int left, int right, int k) {
	    if(left == right) {
	    	return nums[left];
	    }
	    int from = left, end = right;
		int val = nums[left];
		while(left < right) {
			if(nums[left] < val && nums[right] > val){
				swap(nums[left], nums[right]);
			}
			while(nums[left] >= val && right > left) left++;
			while(nums[right] < val && right > left) right--;
		}
		if(left == k-1) {
			return nums[left];
		} else if(left < k-1) {
			return quickSort(nums, left+1, end, k-left-1);
		} else {
			return quickSort(nums, from, left, k);
		}
	}
};