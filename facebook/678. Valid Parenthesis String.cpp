class Solution {
public:
    bool checkValidString(string s) {
        vector<unordered_set<int>> dp(s.size() +1);
        dp[0].insert(0);
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(') {
        		for(int v : dp[i]) {
        			dp[i+1].insert(v+1);
        		}
        	} else if(s[i] == ')') {
        		for(int v : dp[i]) {
        			if(v-1 >= 0) {
        				dp[i+1].insert(v-1);
        			}
        		}
        	} else if(s[i] == '*') {
        		for(int v : dp[i]) {
        			if(v-1 >= 0) {
        				dp[i+1].insert(v-1);
        			}
        			dp[i+1].insert(v+1);
        			dp[i+1].insert(v);
        		}
        	}
        	if(dp[i+1].empty()) {
        		return false;
        	}
        }

		return dp[s.size()].count(0);
    }
};