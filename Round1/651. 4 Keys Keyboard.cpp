class Solution {
public:
    int maxA(int N) {
        int dp[N+1];
        for(int i = 0; i <= N; i++) {
        	if(i < 7) {
        		dp[i] = i;
        	} else {
        		dp[i] = max(dp[i-3]*2, dp[i-4]*3);
        		dp[i] = max(dp[i], dp[i-5]*4);
        	}
        }
        return dp[N];
    }
};