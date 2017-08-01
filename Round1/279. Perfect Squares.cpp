class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        vector<int> dp(n+1, INT_MAX);
        int index = 1;
        for(int i = 1; i <= n; i++) {
        	if(i == index * index) {
        		square.push_back(index * index);
        		index++;
        		dp[i] = 1;
        	} else {
	        	for(int j = 0; j < square.size(); j++) {
	        		dp[i] = min(dp[i], dp[i - square[j]] + 1);
	        	}
        	}
        	// cout<< i << "  " << dp[i] << endl;
        }
        return dp[n];
    }
};