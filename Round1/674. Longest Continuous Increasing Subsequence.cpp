class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    	if(nums.size()== 0) {
    		return 0;
    	}
        int ret = 0, current = 0;
        for(int i = 0; i < nums.size()-1; i++) {
        	if(nums[i+1] <= nums[i]) {
        		ret = max(ret, i - current + 1);
        		current = i+1;
        	}
        }
		ret = max(ret, (int)nums.size()-current);
        return ret;
    }
};