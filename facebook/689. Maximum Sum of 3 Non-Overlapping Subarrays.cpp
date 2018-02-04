class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int>> dp(3, vector<int>(nums.size(), 0));
        vector<int> sums(nums.size(), 0);
        vector<vector<int>> path(3, vector<int>(nums.size(), 0));
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
        	sums[i] = sums[i-1] + nums[i];
        }
        path[0][k-1] = 0;
        dp[0][k-1] = sums[k-1];

        for(int i = k; i < nums.size(); i++) {
        	int ksum = sums[i] -sums[i-k];
        	if(i >= 2 * k && dp[1][i-k] + ksum > dp[2][i-1]) {
        		dp[2][i] = dp[1][i-k] + ksum;
        		path[2][i] = i-k+1;
        	} else {
        		dp[2][i] = dp[2][i-1];
        		path[2][i] = path[2][i-1];
        	}
        	if(i >= k && dp[0][i-k] + ksum > dp[1][i-1]) {
        		dp[1][i] = dp[0][i-k] + ksum;
        		path[1][i] = i-k+1;
        	} else {
        		dp[1][i] = dp[1][i-1];
        		path[1][i] = path[1][i-1];
        	}
        	if(ksum > dp[0][i-1]) {
        		dp[0][i] = ksum;
        		path[0][i] = i-k+1;
        	} else {
        		dp[0][i] = dp[0][i-1];
        		path[0][i] = path[0][i-1];
        	}
        	// cout<< i << "  " << dp[0][i] << "  " << dp[1][i] << "  " << dp[2][i] << endl;
		}
		vector<int> res;
		int pre = path[2][nums.size()-1];
		res.push_back(pre);
		pre = path[1][pre-1];
		res.push_back(pre);
		pre = path[0][pre-1];
		res.push_back(pre);
		reverse(res.begin(), res.end());
		return res;
    }
};