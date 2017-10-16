class Solution {
public:
    int repeatedStringMatch(string A, string B) {
    	int n = A.size(), ret = 1, pos = -1;
        for(int i = 0; i < B.size(); i++) {
        	// cout<<B.substr(i, n) << "  " << A << "  " << i+n << endl;
        	if(i + n <= B.size()) {
        		if(B.substr(i, n) == A) {
        			pos = i;
        			break;
        		}
        	} else {
        		if(B.substr(i) == A.substr(0, B.size()-i)) {
        			pos = i;
        			break;
        		}
        	}
        }

        if(pos < 0) {
        	return -1;
        }
        if(pos != 0) {
       		pos = n - pos;
        }
        // cout<< pos <<endl;
        for(int i = 0; i < B.size(); i++) {
        	if(A[pos] != B[i]) {
        		return -1;
        	}
        	pos++;
        	if(pos == n && i != B.size()-1) {
        		pos = 0;
        		ret++;
        	}
        }
        return ret;
    }
};