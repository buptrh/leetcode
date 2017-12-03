class Solution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() <= 1) {
    		return 0;
    	}
    	int maxLength = 0, maxLength2 = 0;
    	int target = nums.size()-1;
    	int ret = 0;
    	while(true) {
    		int length = maxLength2;
	    	for(int i = maxLength2; i >= maxLength; i--) {
	    		if(nums[i] + i >= target) {
	    			return ret+1;
	    		}
	    		length = max(length, nums[i] + i);
	    	}
	    	ret++;
	    	if(length == maxLength2) {
	    		return 0;
	    	}
	    	maxLength = maxLength2;
	    	maxLength2 = length;
    	}

    	return ret;
    }
};