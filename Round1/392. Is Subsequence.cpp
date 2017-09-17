class Solution {
public:
    bool isSubsequence(string s, string t) {
    	if(s.size() == 0) {
    		return true;
    	}
        int left1 = 0, left2 = 0;
        while(left2 < t.size()) {
        	if(s[left1] == t[left2]) {
        		left1++;
        	}
        	if(left1 == s.size()) {
        		return true;
        	}
        	left2++;
        }
        return false;
    }
};