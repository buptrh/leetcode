class Solution {
public:
    bool isMatch(string s, string p) {
    	vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
    	dp[0][0] = true;

    	for(int i = 0; i <= s.size(); i++) {
    		for(int j = 1; j <= p.size(); j++) {
    			if(p[j-1] == '?') {
    				if(i == 0) {
    					dp[i][j] = false;
    				} else {
    					dp[i][j] = dp[i-1][j-1];
    				}
    			} else if(p[j-1] == '*') {
    				if(i >= 1) {
						dp[i][j] = dp[i-1][j] || dp[i][j-1];
    				} else {
    					dp[i][j] = dp[i][j-1];
    				}
    			} else {
    				if(i == 0) {
    					dp[i][j] = false;
    				} else if(s[i-1] == p[j-1]) {
    					dp[i][j] = dp[i-1][j-1];
    				} else {
    					dp[i][j] = false;
    				}
    			}
    		}
    	}
    	return dp[s.size()][p.size()];

    }

};