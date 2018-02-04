class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    	if(abs((int)s.size() - (int)t.size()) >= 2) {
    		return false;
    	}
    	int j = 0;
    	bool changed = false;
        for(int i = 0; i < s.size(); i++, j++) {
        	if(j >= t.size() || s[i] != t[j]) {
        		if(changed) {
        			return false;
        		}
        		changed = true;
        		if(s.size() < t.size()) {
        			i--;
        		} else if(s.size() > t.size()) {
        			j--;
        		}
        	}
        }
        return changed || (s.size() != t.size());
    }
};