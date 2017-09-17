class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int ret = 0, current = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == 1) {
        		current++;
        	} else {
        		ret = max(ret, current);
        		current = 0;
        	}
        }
		ret = max(ret, current);
        return ret;
    }
};