class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	int count = 0;
        string s2, s3;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(') {
        		count++;
        		s2.push_back(s[i]);
        	} else if(s[i] == ')') {
        		if(count > 0) {
        			count--;
        			s2.push_back(s[i]);
        		}
        	} else {
        		s2.push_back(s[i]);
        	}
        }

        count = 0;
        for(int i = s2.size()-1; i >= 0; i--) {
        	if(s2[i] == ')') {
        		count++;
        		s3.push_back(s2[i]);
        	} else if(s2[i] == '(') {
        		if(count > 0) {
        			count--;
        			s3.push_back(s2[i]);
        		}
        	} else {
        		s3.push_back(s2[i]);
        	}
        }
        reverse(s3.begin(), s3.end());
        std::vector<string> v;
        v.push_back(s3);
        return v;
    }
};