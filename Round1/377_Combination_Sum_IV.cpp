class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+1] ;
        for(int i = 0; i <= target; i++) {
        	dp[i] = -1;
        }
        return solve(nums, dp, target);
    }

    int solve(vector<int>& nums, int * dp, int target) {
    	if( target == 0) {
    		return 1;
    	} else if(target < 0) {
    		return 0;
    	}
    	if(dp[target] != -1) {
    		return dp[target];
    	}
    	int res = 0;
    	for(int i = 0; i < nums.size(); i++) {
			res += solve(nums, dp, target - nums[i]);
    	}
    	dp[target] = res;
    	return res;
    }

};