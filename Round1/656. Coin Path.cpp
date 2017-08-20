class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
    	if(A.size() == 0 || A[A.size()-1] == -1) {
    		return std::vector<int>();
    	}
        vector<int> dp(A.size()+1, 100000);
        vector<vector<int>> path(A.size()+1, vector<int>());

        for(int i = A.size()-1; i >= 0; i--) {
        	if(i == A.size()-1) {
        		dp[i] = A[i];
        		path[i].emplace_back(i+1);
        	} else if(A[i] == -1){
        		dp[i] = 100000;
        	} else {
        		int val = 0, index = 0;
        		for(int j = B; j >= 1; j--) {
        			if(i+j < A.size()) {
        				if(dp[i+j] < 99999 && dp[i] >= dp[i+j]) {
        					dp[i] = dp[i+j];
        					path[i] = path[i+j];
        					index = i+j;
        				}
        			}
        		}
        		dp[i] += A[i];
        		// cout<<"dp" << i << "  "<< dp[i] << endl;
        		// cout<<"path" << i << "  ";
        		// for(int m = 0; m < path[i].size(); m++) {
        		// 	cout<<path[i][m] << "  ";
        		// }
        		// cout<<endl;
        		if(dp[i] < 99999) {
        			path[i].emplace_back(i+1);
        		}
        	}
        }

        reverse(path[0].begin(), path[0].end());
        return path[0];
    }
};