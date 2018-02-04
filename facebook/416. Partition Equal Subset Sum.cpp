class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) {
        	sum += i;
        }
        if(sum % 2 != 0) {
        	return false;
        }

        vector<vector<bool>> dp(sum/2+1, vector<bool>(nums.size()+1, false));

        for(int i = 0; i <= nums.size(); i++) {
        	dp[0][i] = true;
        }
        for(int i = 0; i <= sum/2; i++) {
        	for(int j = 1; j <= nums.size(); j++) {
        		if(i - nums[j-1] >= 0) {
        			dp[i][j] = (dp[i][j-1] || dp[i-nums[j-1]][j-1]);
        		}
        	}
        }

        return dp[sum/2][nums.size()];
    }
};