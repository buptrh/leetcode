class Solution {
public:
    int minSteps(int n) {
		int dp[n+1];
        for(int i = 1; i <= n; i++) {
            dp[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                dp[i] = 0;
                continue;
            } else if (dp[i] == 0) {
                dp[i] = i;
            }
            for(int j = i/2; j > 1; j--) {
                if(i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i/j);
                    break;
                }
            }
        }
        return dp[n];
    }
};