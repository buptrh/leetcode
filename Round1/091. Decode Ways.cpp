class Solution {
public:
    int numDecodings(string s) {
    	if(s.size() == 0) {
    		return 0;
    	}

    	vector<int> dp(s.size()+2, 0);
    	dp[s.size()-1] = 1;
    	dp[s.size()] = 1;

    	if(s[s.size()-1] == '0') {
    		dp[s.size()-1] = 0;
    	}
    	if(s.size() >= 2 && findCount(s, s.size()-2) == 0 ) {
    		dp[s.size()] = 0;
    	}


    	for(int i = s.size()-2; i >= 0; i --) {
    		if(s[i] != '0') {
				dp[i] = dp[i+1];
    		}
    		if(findCount(s, i) == 2) {
    			dp[i] += dp[i+2];
    		}
    	}
    	return dp[0];
    }

    int findCount(string s, int start) {
    	int ret = 0;
    	if(s[start] == '0') {
    	} else if(s[start+1] == '0' && (s[start] == '0' || s[start] > '0' + 2)) {
    	} else if(s[start] == '0'+1 || (s[start] == '0'+2 && s[start+1] <= '0'+6)) {
    		ret = 2;
    	} else {
    		ret = 1;
    	}
    	return ret;
    }
};