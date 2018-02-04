class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
		for (int j = 1; j <= p.size(); j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        for(int i = 1; i <= s.size(); i++) {
        	for(int j = 1; j <= p.size(); j++) {
        		if(p[j-1] == '*') {
        			dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
        		} else {
        			dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
        		}
        	}
        }
        return dp[s.size()][p.size()];
    }
};



/*class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }

    bool helper(string & s, int s1, string & p, int s2) {
    	if(s1 == s.size() && s2 == p.size()) {
    		return true;
    	} else if(s2 == p.size()) {
    		return false;
    	} else if(s1 == s.size() && (s2 >= p.size()-1 || p[s2+1] != '*')) {
    		return false;
    	}
    	// cout<< s1 << "  " << s2 << endl;
    	if(p[s2] == '.') {
    		if(s2 < p.size()-1 && p[s2+1] == '*') {
    			for(int i = s1; i <= s.size(); i++) {
    				if(helper(s, i, p, s2+2)) {
    					return true;
    				}
    			}
    		} else {
    			return helper(s, s1+1, p, s2+1);
    		}
    	} else {

    		if(s2 < p.size()-1 && p[s2+1] == '*') {
    			if(helper(s, s1, p, s2+2)) {
    				return true;
    			}
				for(int i = s1; i < s.size(); i++) {
    				if(s[i] == p[s2]) {
    					if(helper(s, i+1, p, s2+2)) {
    						return true;
    					}
    				} else {
    					break;
    				}
    			}
    		} else {
    			if(s[s1] == p[s2]) {
    				return helper(s, s1+1, p, s2+1);
    			}
    		}
    	}
    	return false;
    }
};*/