class Solution {
public:
    bool checkValidString(string s) {
    	int left = 0;
    	return helper(s, 0, left);
    }

    bool helper(string s, int start, int left) {
    	if(left < 0) {
    		return false;
    	}
    	while(start < s.size()) {
    		if(s[start] == '(') {
    			left++;
    			start++;
    		} else if(s[start] == ')') {
    			left --;
    			if(left < 0) {
    				return false;
    			}
    			start++;
    		} else if(s[start] == '*') {
    			start++;
    			return helper(s, start, left) || helper(s, start, left+1) || helper(s, start, left-1);
    		} else {
    			start++;
    		}
    	}

    	return (left == 0);
    }
};