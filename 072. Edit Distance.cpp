class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= word1.size(); i++) {
        	dp[i][0] = i;
        }
        for(int j = 1; j <= word2.size(); j++) {
        	dp[0][j] = j;
        }
        for(int i = 0; i < word1.size(); i++) {
        	for(int j = 0; j < word2.size(); j++) {
        		if(word1[i] == word2[j]) {
        			dp[i+1][j+1] = dp[i][j];
        		} else {
        			dp[i+1][j+1] = min(dp[i+1][j], min(dp[i][j+1], dp[i][j]))+1;
        		}
        	}
        }
        return dp[word1.size()][word2.size()];
    }
};