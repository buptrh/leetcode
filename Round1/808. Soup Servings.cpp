class Solution {
public:
    double soupServings(int N) {
        double ret = 0.0;
        vector<int> Avals {100, 75, 50, 25};
        vector<int> Bvals {0, 25, 50, 75};
        int A = N;
        int step = 0;
        vector<double> dp (N/100+1, 0);
        dp[N/100] = 1;
        while(true) {
        	vector<double> dpnew (N/100+1, 0);
        	bool flag = false;
        	for(int i = 0; i < dp.size(); i++) {
        		cout<<i << "  " << dp[i]<<endl;
        		if(dp[i] == 0) {
        			continue;
        		}
        		flag = true;
        		int B = 2*(N/100) - i;
        		if(B == 3 && i == 1) {
        			ret += dp[i] + 0.25*0.5;
        		} else if(i <= 1) {
        			ret += dp[i] + 0.25;
        		} else {
        			dpnew[i-1] = dp[i] * 0.25;
        		}

        		if(B == 2 && i <= 2) {
        			ret += dp[i] + 0.25*0.5;
        		} else if(i <= 2) {
        			ret += dp[i] + 0.25;
        		} else {
        			dpnew[i-2] = dp[i] * 0.25;
        		}

        		if(B == 1 && i <= 3) {
        			ret += dp[i] + 0.25*0.5;
        		} else if(i <= 3) {
        			ret += dp[i] + 0.25;
        		} else {
        			dpnew[i-3] = dp[i] * 0.25;
        		}

        		if(i <= 4) {
        			ret += dp[i] + 0.25;
        		} else {
        			dpnew[i-4] = dp[i] * 0.25;
        		}
        	}
        	if(!flag) {
        		break;
        	}
        }
        return ret;
    }
};