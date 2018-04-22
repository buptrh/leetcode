class Solution {
public:
    bool rotateString(string A, string B) {
    	if(A.size() != B.size()) {
    		return false;
    	}
        for(int i = 0; i < A.size(); i ++) {
        	bool flag = true;
        	for(int j = 0; j < B.size(); j++) {
        		if(A[j] != B[(i+j)%B.size()]) {
        			flag = false;
        			break;
        		}
        	}
        	if(flag == true) {
        		return true;
        	}
        }
        return false;
    }
};