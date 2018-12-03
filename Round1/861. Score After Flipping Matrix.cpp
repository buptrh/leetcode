class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
    	if(A.size() == 0 || A[0].size() == 0) {
    		return 0;
    	}
    	// cout<< 0 << endl;
    	int m = A.size(), n = A[0].size();
    	for(int i = 0; i < A.size(); i++) {
    		if(A[i][0] == 0) {
    			for(int j = 0; j < n; j++) {
    				if(A[i][j] == 0) {
    					A[i][j] = 1;
    				} else {
    					A[i][j] = 0;
    				}
    			}
    		}
    	}
    	// cout<< 1 << endl;

    	for(int j = 0; j < n; j++) {
    		int sum = 0;
    		for(int i = 0; i < m; i++) {
    			if(A[i][j] == 1) {
    				sum++;
    			}
    		}
    		if(sum * 2 < m) {
    			for(int i = 0; i < m; i++) {
    				if(A[i][j] == 0) {
    					A[i][j] = 1;
    				} else {
    					A[i][j] = 0;
    				}
    			}
    		}
    	}
    	// cout<< 2 << endl;

    	int res = 0;
    	for(int i = 0; i < m; i++) {
    		int sum = 0;
			for(int j = 0; j < n; j++) {
				sum *= 2;
				sum += A[i][j];
			}
			res += sum;
    	}
    	return res;
    }
};