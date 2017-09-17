class Solution {
public:
    int rob(vector<int>& nums) {
    	switch(nums.size()) {
    		case 0:
    			return 0;
    			break;
    		case 1:
    			return nums[0];
    			break;
    		case 2:
    			return max(nums[0], nums[1]);
    			break;
    		case 3:
    			return max(nums[0] + nums[2], nums[1]);
    			break;
    	}
        int * sum = new int[nums.size()];
        sum[0] = nums[0];
        sum[1] = nums[1];
        sum[2] = nums[2] + sum[0];
        for (int i = 2; i < nums.size(); i++) {
        	sum[i] = max(sum[i-2], sum[i-3]) + nums[i];
        }
        int ret =  max(sum[nums.size()-1], sum[nums.size()-2]);
        delete [] sum;
        return ret;
    }
};


//my solution has too mush useless switch/case