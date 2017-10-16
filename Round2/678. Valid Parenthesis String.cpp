class Solution {
public:
    bool checkValidString(string s) {
    	int low = 0, high = 0;
    	for(int i = 0; i < s.size(); i++) {
    		if(s[i] == '(') {
    			low ++;
    			high++;
    		} else if(s[i] == ')') {
    			if(high <= 0) {
    				return false;
    			}
    			high --;
    			low --;
    		} else {
    			low --;
    			high ++;
    		}

    		if(low < 0) {
    			low = 0;
    		}
    	}
    	return low == 0;
    }

};