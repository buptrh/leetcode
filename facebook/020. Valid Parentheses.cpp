class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char c : s) {
        	if(c == '(' || c == '[' || c =='{') {
        		sta.push(c);
        	} else if(!sta.empty() && ((c == ')' && sta.top() == '(') || (c == ']' && sta.top() == '[') || (c == '}' && sta.top() == '{'))) {
        		sta.pop();
        	} else {
        		return false;
        	}
        }
        return sta.empty();
    }
};