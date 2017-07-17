class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> sta;
        for(int i = 0; i < tokens.size(); i++ ) {
        	int val1 = 0, val2 = 0;
        	if(tokens[i] == "+") {
        		val2 = sta.top();
        		sta.pop();
        		val1 = sta.top();
        		sta.pop();
        		val1 = val1 + val2;
        		sta.push(val1);
        	} else if(tokens[i] == "-") {
        		val2 = sta.top();
        		sta.pop();
        		val1 = sta.top();
        		sta.pop();
        		val1 = val1 - val2;
        		sta.push(val1);
        	} else if(tokens[i] == "*") {
        		val2 = sta.top();
        		sta.pop();
        		val1 = sta.top();
        		sta.pop();
        		val1 = val1 * val2;
        		sta.push(val1);
        	} else if(tokens[i] == "/") {
        		val2 = sta.top();
        		sta.pop();
        		val1 = sta.top();
        		sta.pop();
        		val1 = val1 / val2;
        		sta.push(val1);
        	} else {
        		sta.push(stoi(tokens[i]));
        	}
        }
        return sta.top();
    }
};