class Solution {
public:
    int flipLights(int n, int m) {
    	if(n == 0) {
    		return 0;
    	}
    	if(n > 3) {
    		n = 3;
    	}
    	if(m == 0) {
    		return 1;
    	} else if(n == 1) {
    		return 2;
    	} else if(n == 2) {
    		if(m == 1) {
    			return 3;
    		}
    		return 4;
    	} else {
    		if(m == 1) {
				return 4;
			} else if(m == 2) {
				return 7;
			}
    		else {
    			return 8;
    		}
    	}

    }
};