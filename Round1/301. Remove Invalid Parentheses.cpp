class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        if(s.size() == 0) {
        	ret.push_back("");
        	return ret;
        }
        vector<char> prefix{'(', ')'};
		helper(s, 0, 0, prefix, ret);
		return ret;
    }

    void helper(string s, int last_i, int last_j, vector<char> prefix, vector<string> & ret) {
    	int stack = 0;
    	// cout<<"check: " << s << endl;
    	for(int i = last_i; i < s.size(); i++) {
    		if(s[i] == prefix[0]) {
    			stack++;
    		} else if(s[i] == prefix[1]) {
    			stack--;
    		}
    		if(stack < 0) {
    			for(int j = last_j; j <= i; j++) {
    				if(s[j] == prefix[1] && (j == last_j || s[j-1] != s[j])) {
    					helper(s.substr(0, j) + s.substr(j+1), i, j, prefix, ret);
    				}
    			}
    			return;
    		} else {
    			continue;
    		}
    	}
    	// cout<<"out: "<<s<<endl;
    	reverse(s.begin(), s.end());
    	if( prefix[0] == ')') {
    		// cout<<"ret: "<<s<<endl;
    		ret.push_back(s);
    	} else {
        	vector<char> prefix{')', '('};
    		helper(s, 0, 0, prefix, ret);
    	}

    }
};