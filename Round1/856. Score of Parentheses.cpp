class Solution {
public:
    int scoreOfParentheses(string S) {
    	int pos = 0;
        return helper(S, pos)/2;
    }

    int helper(string& S, int &pos) {
    	int ret = 0;
    	int start = pos;
    	while(pos < S.size()) {
    		if(S[pos] == ')') {
    			pos++;
    			if(ret == 0) {
    				return 1;
    			} else {
    				return ret * 2;
    			}
    		} else {
    			pos++;
    			ret += helper(S, pos) ;
    		}
    	}
    	return ret * 2;
    }
};