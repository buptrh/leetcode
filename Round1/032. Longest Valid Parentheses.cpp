class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(sta.size() == 0 || s[i] == '(' || s[i] == '[') {
        		sta.push(i);
        	} else {
        		int c = sta.top();
        		if((s[i] == ')' && s[c] == '(') || (s[i] == ']' && s[c] == '[')) {
        			sta.pop();
        			if(sta.size() == 0) {
        				res = max(res, i+1);
        			} else {
        				res = max(res, i - sta.top());
        			}
        		} else {
        			sta.push(i);
        		}
        	}
        }
        return res;
    }
};