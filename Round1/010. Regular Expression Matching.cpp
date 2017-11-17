class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(p, 0, s, 0);
    }

    bool helper(string & s, int s1, string & p, int p1) {
    	// cout<<s1 << "  " << p1 << endl;
    	if(s1 == s.size() && p1 == p.size()) {
    		return true;
    	}
    	if(s1 > s.size() || p1 > p.size() ) {
    		return false;
    	}

    	if(s[s1] == '.') {
    		if(s1+1 < s.size() && s[s1+1] == '*') {
    			for(int i = 0; p1+i <= p.size(); i++) {
    				if(helper(s, s1+2, p, p1 + i)) {
    					return true;
    				}
    			}
    		} else {
    			return helper(s, s1+1, p, p1+1);
    		}
		} else {
			if(s1+1 < s.size() && s[s1+1] == '*') {
				char c = s[s1];
				if(helper(s, s1+2, p, p1)) {
					return true;
				}
    			for(int i = 0; p1+i < p.size(); i++) {
    				if(p[p1+i] == c) {
    					if(helper(s, s1+2, p, p1 + i + 1)) {
    						return true;
    					}
    				} else {
    					break;
    				}
    			}
    		} else {
    			if(s[s1] == p[p1]){
    				return helper(s, s1+1, p, p1+1);
    			}
    		}
    	}

    	return false;

    }
};