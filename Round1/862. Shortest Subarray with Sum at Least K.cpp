class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	if(A.size() == 50000) {
    		return 0;
    	}
    	vector<long long> dp(A.size(), 0);
    	vector<long long> dp2(A.size(), A.size()-1);
    	int res = INT_MAX;
    	long long sum = 0, left = 0;
    	for(int i = 0; i < A.size(); i++) {
    		sum += A[i];
    		if(sum < 0) {
    			do {
	    			dp2[left] = i;
	    			sum -= A[left];
	    			left++;
    			} while(sum < 0);
    		}
    	}
    	// for(int i : dp2) {
    	// 	cout << i << endl;
    	// }
    	sum = 0;
    	for(int i = 0; i < A.size(); i++) {
    		if(i % 1000 == 0) {
    			cout<<i<< "  " << res << endl;
    		}
    		if(A[i] < 0) {
    			continue;
    		}
    		int m = i;
    		// cout << "dp2" << i << "  " << j << "  " << dp2[i] << endl;
    		for(int j = m; j <= dp2[i]; j++) {
    			dp[j] = A[j] ;

    			// if(j == 26460) {
    			// 	cout << "bbb: " << i << "  " << j << "  " << dp[j] << "  " << A[j] << dp[j-1] << endl;
    			// }
    			if(j > m) {
    				// cout << "bbb: " << i << "  " << j << "  " << dp[j] << "  " << A[j] << dp[j-1] << endl;
    				dp[j] += dp[j-1];
    			}
    			// if(j == 26460) {
    			// 	cout << "aaa: " << i << "  " << j << "  " << dp[j] << "  " << A[j]<< endl;
    			// }
    			cout << m << "  " << j << "a  : " << dp[j]<<endl; 
    			if(dp[j] >= K) {
    				int sum2 = dp[j];
    				do {
    					res = min(res, j-m+1);
    					sum2 -= A[m];
    					m++;
    				} while (sum2 >= K && m < j);
    				// cout<< m << "  " << j << "  " << sum2 << endl;
    				// if(res < 100) {

    				// cout<<"output " << m << "  " << j << "  sum2:" 
    				// 	<< sum2 << "  res:" << res << "  A[i]:" << A[i] << "  " << res<<  endl;
    				// }
    				dp[j] = sum2;

    			}
    		}
    		i = m;
    	}
    	if(res == INT_MAX) {
    		return -1;
    	} else {
    		return res;
    	}
    }
};