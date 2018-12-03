class Solution {
public:
    bool buddyStrings(string A, string B) {
    	if(A.size() < 2 || B.size() < 2  || A.size() != B.size()) {
    		return false;
    	}
    	char a = 0, b = 0;
    	bool ret = false;
        for(int i = 0; i < A.size(); i++) {
        	if(A[i] != B[i]) {
        		if(a == 0) {
        			a = A[i];
        			b = B[i];
        		} else if(ret == true) {
        			return false;
        		} else {
        			if(A[i] == b && B[i] == a) {
        				ret = true;
        			} else {
        				return false;
        			}
        		}
        	}
        }
        if(!ret) {
        	unordered_set<char> dup;
        	for(int i = 0; i < A.size(); i++) {
        		if(dup.count(A[i]) > 0) {
        			return true;
        		}
        		dup.insert(A[i]);
        	}
        }
        return ret;
    }
};