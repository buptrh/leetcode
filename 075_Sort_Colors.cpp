class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = sortColor(nums, 0, nums.size() - 1, 0);
        sortColor(nums, red, nums.size()-1, 1);
    }

    int sortColor(std::vector<int>& nums, int start, int end, int value) {
    	while(start < end) {
    		while(nums[start] == value && start < end) {
    			start++;
    		}
    		while(nums[end] != value && end > start) {
    			end--;
    		}
    		if(start < end) {
				nums[end] = nums[start];
				nums[start] = value;
    		}
    	}
    	return start;
    }
};

//can do in one loop