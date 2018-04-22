class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        if(A.size() <= 1) {
        	return 0;
        }
    	int total = A.size();
    	int inpos = 0;
    	int res1 = 0, res2 = 0, res = 0;
    	unordered_set<int> numset;
    	bool flag = true;
        for(int i = 0; i < A.size(); i++) {
        	if( i > 0) {
	        	if(A[i] > A[i-1] && A[i] > B[i-1] && B[i] > B[i-1] && B[i] > A[i-1]) {
		    		res += min(res1, res2);
		    		// cout<<"res: " << res << endl;
		    		res1 = 0;
		    		res2 = 0;
	        	} else {
	        		flag = false;
	        		numset.insert(i);
	        		total++;
	        		
	    			if(A[i] < B[i]) {
	    				res2++;
	    			} else{
	    				res1++;
	    			}
	        		// cout<< i << "  " << A[i] << ":  " << res1 << "  " << res2<< endl;
	    			continue;;
	        	}
        	}

        	if( i < A.size() - 1) {
	        	if(A[i] < A[i+1] && A[i] < B[i+1] && B[i] < B[i+1] && B[i] < A[i+1]) {
	        	} else {
	        		flag = false;
	        		numset.insert(i);
	        		total++;
	        		
	    			if(A[i] < B[i]) {
	    				res2++;
	    			} else{
	    				res1++;
	    			}
	        		// cout<< "!!!" << i << "  " << A[i] << ":  " << res1 << "  " << res2 << endl;
	    			continue;;
	        	}
        	}
        }
		res += min(res1, res2);
		// cout<<"final res: " << res << endl;
        return res;

    }
};