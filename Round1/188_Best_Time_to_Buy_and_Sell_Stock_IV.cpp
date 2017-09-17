class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	if(prices.size() <= 0 || k <= 0) {
    		return 0;
    	}
    	if(k > prices.size()) {
    	    k = prices.size();
    	}
    	vector<int> buy (k, INT_MIN);
    	vector<int> sell (k, 0);
        for(int i = 0; i < prices.size(); i++) {
            int cur = prices[i];
        	for(long j = k-1; j >= 0; j--) {
        		sell[j] = max(sell[j], buy[j] + cur);
        		if(j == 0) {
        			buy[j] =  max(buy[j], - cur);
        		} else {
        			buy[j] = max(buy[j], sell[j-1] - cur);
        		}
        	}
        }
        return sell[k-1];
    }
};

// [1,4,6,2,6,3].   0 -1. 0. -1.   ->. 3 -1 3 -1   ->5 -1 5 -1   ->5, 3, 5, -2. ->9
//