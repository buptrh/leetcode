class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+3, 0);
        for(int i = 0; i <= cost.size(); i++) {
        	dp[i+2] = min(dp[i+1], dp[i]) ;
        	if(i != cost.size()) {
        		dp[i+2] += cost[i];
        	}
        }
        return dp[cost.size()+2];
    }
};