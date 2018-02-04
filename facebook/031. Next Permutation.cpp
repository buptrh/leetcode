class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i = nums.size()-1; i > 0; i--) {
        	if(nums[i] > nums[i-1]) {
        		index = i-1;
        		break;
        	}
        }

        if(index < 0) {
        	reverse(nums.begin(), nums.end());
        } else {
	        for(int i = nums.size()-1; i >= index; i--) {
	        	if(nums[i] > nums[index]) {
	        		swap(nums[i], nums[index]);
	        		break;
	        	}
	        }
	        vector<int>::iterator iFrom = nums.begin();
	        iFrom = iFrom + index + 1;

	        reverse(iFrom, nums.end());

        }
    }
};