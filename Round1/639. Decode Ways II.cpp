class Solution {
public:
	// map<int, int> table;
    int numDecodings(string s) {
    	if(s.size() == 0) {
    		return 0;
    	}
    	
    	long long dev = 1e9 + 7;
    	long long ret = 0, ret1 = 0, current = 1, current1 = 1;

    	for(int i = s.size()-1; i >= 0; i--) {
    		int v = 1;
    		if(s[i] == '*') {
    			v = 9;
    		} else if(s[i] == '0') {
    			v = 0;
    		}
    		ret = (v * current + ret1) % dev;
    		// cout << "!! " << current<< "  " << ret1<< "  " << ret << endl;
    		ret1 = 0;
    		if(i > 0) {
    			int v1 = 0;
    			if(s[i-1] == '1') {
    				v1 = 1;
    				if(s[i] == '*') {
    					v1 = 9;
    				}
    			} else if(s[i-1] == '2') {
    				if(s[i] == '*') {
    					v1 = 6;
    				} else if(s[i] > '6') {
    					v1 = 0;
    				} else {
    					v1 = 1;
    				}
    			} else if(s[i-1] == '*') {
    				if(s[i] == '*') {
    					v1 = 15;
    				} else if(s[i] > '6') {
    					v1 = 1;
    				} else {
    					v1 = 2;
    				}
    			} else {
    				v1 = 0;
    			}

    			if(v1 != 0) {
    				ret1 = (v1 * current1) % dev;
    			}
    		}

    		current = ret;
    		current1 = current;
    		// cout << "current" << current<< "  ret1:" << ret1<< "  ret:" << ret << endl;
    	}

    	ret += ret1;

    	ret = ret % dev;
    	return ret;
    }

};