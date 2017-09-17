//o(n*k*k) solution
class Solution {
public:
    int kInversePairs(int n, int k) {
    	long long arr[n+1][k+1] = {0};
    	long long mod = pow(10, 9) + 7;
    	for(int i = 1; i <= n; i++) {
			arr[i][0] = 1;
    	}
    	for(int i = 2; i <= n; i++) {
    		for(int j = 1; j <= k; j++) {
    			for(int m = 0; m <= j; m++) {
    				if( i > j-m && i > 1){
    					arr[i][j] = (arr[i][j] + arr[i-1][m]) % mod;
    		cout<<"++ " << i << " " << j << "  " << m << " = " << arr[i-1][m]<<endl;
    				}
    			}
    		cout<<i << "  " << j << " = " << arr[i][j]<<endl;
    		}
    	}
    	// cout<<arr[n][k] << "  " << mod << "  " << arr[n][k]%mod;
        return arr[n][k];
    }
};

//o(n*k) solution
class Solution {
public:
    int kInversePairs(int n, int k) {
    		vector<vector<long long> > arr(n+1, vector<long long>(k+1, 0));
    	// long long arr[n+1][k+1] = {0};
    	long long mod = pow(10, 9) + 7;
    	for(int i = 1; i <= n; i++) {
			arr[i][0] = 1;
    	}
    	for(int i = 2; i <= n; i++) {
    		for(int j = 1; j <= k; j++) {
    			arr[i][j] = (arr[i][j-1] + arr[i-1][j] );
    			if(j-i >= 0) {
    				arr[i][j] = (arr[i][j] - arr[i-1][j-i]);
    			}
    			arr[i][j] = (arr[i][j] + mod) % mod;
    		// 	for(int m = 0; m <= j; m++) {
    		// 		if( i > j-m && i > 1){
    		// 			arr[i][j] = (arr[i][j] + arr[i-1][m]) % mod;
    		// // cout<<"++ " << i << " " << j << "  " << m << " = " << arr[i-1][m]<<endl;
    		// 		}
    		// 	}
    		// cout<<i << "  " << j << " = " << arr[i][j]<<endl;
    		}
    	}
    	// cout<<arr[n][k] << "  " << mod << "  " << arr[n][k]%mod;
        return arr[n][k];
    }
};



