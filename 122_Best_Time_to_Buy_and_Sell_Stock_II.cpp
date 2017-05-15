class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int profit = 0;
    	if(prices.size() <= 1) {
    		return profit;
    	}
        for(int i = 0; i < prices.size()-1; i++) {
        	if(prices[i+1] > prices[i]) {
        		profit += prices[i+1] - prices[i];
        	}
        }
        return profit;
    }
};

//100 3 100 8 1 4 2 8
