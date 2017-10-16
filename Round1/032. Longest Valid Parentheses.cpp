class Solution {
public:
    int longestValidParentheses(string s) {
    	int ret1 = 0, length = 0, current = 0;
    	vector<int> remove(s.size(), 1);
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(') {
        		length++;
        	} else if(length > 0) {
        		length--;
        		current++;
        		ret1 = max(ret1, current);
        	} else {
        		remove[i] = 0;
        		current = 0;
        	}
        }
        length = 0, current = 0, ret1 = 0;
        for(int i = s.size()-1; i >= 0; i--) {
        	if(remove[i] == 0) {
        		current = 0;
        		continue;
        	}
        	if(s[i] == ')') {
        		length++;
        	} else if(length > 0) {
        		length--;
        		current ++;
        		ret1 = max(ret1, current);
        	} else {
        		current = 0;
        	}
        }
        return ret1*2;
    }
};