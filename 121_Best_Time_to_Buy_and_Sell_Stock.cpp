class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int ret = 0, minBuy = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
        	if(prices[i] > minBuy) {
        		ret = max(ret, prices[i] - minBuy);
        	}
        	if(prices[i] < minBuy) {
        		minBuy = prices[i];
        	}
        }
        return ret;
    }
};

//100 3 100 8 1 4 2 8
//remember to use max and min