class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> table;
        vector<int> dp(T.size()+1, 0);
        int maxIndex = 0;
        string ret;
        for(int i = 0; i < S.size(); i++) {
        	for(int j = T.size()-1; j >= 0; j--) {
        		if(j > maxIndex) {
        			continue;
        		}
        		if(S[i] == T[j]) {
        			if(j == 0) {
        				dp[j] = i;
        			} else {
        				dp[j] = dp[j-1];
        			}
        			// cout<< j << "  " << dp[j] <<endl;
        			maxIndex = max(maxIndex, j+1);

	        		if(j == T.size()-1) {
	        			// cout<<"output:" << dp[j] <<". " << dp2[j]<<endl;
	        			if(ret.size() == 0 || ret.size() > i - dp[j]+1) {
	        				ret = S.substr(dp[j], i - dp[j]+1);
	        			}
	        		}
        		}
        	}
        }
        return ret;
    }
};