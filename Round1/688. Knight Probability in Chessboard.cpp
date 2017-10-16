class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
    	int left = -r, right = N-r-1, top = -c, bottom = N-c-1;
        vector<vector<int>> dp (2, vector<int>(4*K+1, 0));
        dp[0][2*K] = 1;
        cout<<"!!!" << 2*K << "  " <<dp[0][2*K]<<endl;
        for(int i = 0; i < K; i++) {
        	for(int j = 0; j < 4*K+1; j++) {
        		if(dp[0][j] > 0) {
        			dp[1][j+1] += dp[0][j];
        			dp[1][j+2] += dp[0][j];
        			dp[1][j-1] += dp[0][j];
        			dp[1][j-2] += dp[0][j];
        		}
        	}
        	for(int j = 0; j < 4*K+1; j++) {
        		cout<< j << "  " << dp[1][j]<<endl;
        	}
    		dp[0] = dp[1];
    		dp[1] = vector<int>(4*K+1, 0);
        }
        int count1 = 0, count2 = 0;
        for(int i = left; i <= right; i++) {
    		count1 += dp[0][2*K+i];
        }
    	for(int j = top; j <= bottom; j++) {
    		count2 += dp[0][2*K+j];
    	}
    	count2 *= count1;
        cout<<"final " << count2<<endl;;
        return (double)count2 / ((double)pow(4,K)*pow(4,K));
    }
};