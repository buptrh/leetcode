class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
        		sta.push(s[i]);
        	} else {
        		if(sta.empty()) {
        			return false;
        		}
        		char top = sta.top();
        		if((top == '(' && s[i] == ')') || (top == '[' && s[i] == ']') || (top == '{' && s[i] == '}')) {
        			sta.pop();
        		} else {
        			return false;
        		}
        	}
        }
        if(sta.empty()) {
        	return true;
        } else {
        	return false;
        }
    }
};