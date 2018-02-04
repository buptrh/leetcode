class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0) {
    		return 0;
    	}
        vector<int> buy(prices.size(), INT_MIN), sell(prices.size(), INT_MIN);
        for(int i = 0; i < prices.size(); i++) {
        	if(i > 1) {
        		buy[i] = max(buy[i], sell[i-2]-prices[i]);
        	}
        	if(i > 0) {
        		buy[i] = max(buy[i], buy[i-1]);
        	}
    		buy[i] = max(buy[i], -prices[i]);
    		if(i > 0) {
    			sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
    		} else {
    			sell[i] = 0;
    		}
        }
        return sell[prices.size()-1];
    }
};