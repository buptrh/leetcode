class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> dpCount(nums.size(), 1);
        int longest = 0, ret = 0;
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = 0; j < i; j++) {
        		if(nums[i] > nums[j]) {
        			if(dp[j]+1 > dp[i]) {
        				dp[i] = dp[j]+1;
        				dpCount[i] = dpCount[j];
        			} else if(dp[j] + 1 == dp[i]) {
        				dpCount[i] += dpCount[j];
        			}
        		}
        	}
        	if(dp[i] > longest) {
        		ret = dpCount[i];
        		longest = dp[i];
        	} else if(dp[i] == longest) {
        		ret += dpCount[i];
        	}
        	// cout<<i << "  " << dp[i] << "  " << dpCount[i] << endl;
        }
        return ret;
    }
};