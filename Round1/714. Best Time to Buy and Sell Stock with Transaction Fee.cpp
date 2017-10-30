class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    	if(prices.size() == 0) {
    		return 0;
    	}
        vector<int> dpBuy(prices.size(), 0), dpSell(prices.size(), 0);
        dpBuy[0] = -prices[0];

        for(int i = 1; i < prices.size(); i++) {
        	dpBuy[i] = max(dpBuy[i-1], dpSell[i-1] - prices[i]);
        	dpSell[i] = max(dpSell[i-1], dpBuy[i-1] + prices[i]-fee);
        }
        return dpSell[prices.size()-1];
    }
};