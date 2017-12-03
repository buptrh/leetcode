class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
    	for(int j : coins) {
        	for(int i = j; i <= amount; i ++) {
        		if(i-j < 0) {
        			break;
        		} else {
        			dp[i] += dp[i-j];
        		}
        	}
        }
        return dp[amount];

    }
};