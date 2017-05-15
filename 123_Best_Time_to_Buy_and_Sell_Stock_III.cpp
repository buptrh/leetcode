class Solution {
public:
	int maxProfit1(vector<int>& prices, int & start, int & end) {
    	int maxPrice = 0, minBuy = INT_MAX, minIndex = 0;
        for(int i = 0; i < prices.size(); i++) {
        	if(prices[i] - minBuy > maxPrice) {
        		maxPrice = prices[i] - minBuy;
        		start = minIndex;
        		end = i;
        	}
        	if(prices[i] < minBuy) {
        		minBuy = prices[i];
        		minIndex = i;
        	}
        }
        return maxPrice;
    }
    int maxProfit(vector<int>& prices) {
    	if(prices.size() <= 1) {
    		return 0;
    	}
    	int start, end, start1, end1;
    	int max1 = maxProfit1(prices, start, end);
    	if(max1 == 0) {
    		return 0;
    	}

    	vector<int>::iterator first = prices.begin() + start;
		vector<int>::iterator last = prices.begin() + end + 1;

		vector<int> newVec1(prices.begin() + start,  prices.begin() + end + 1);
  		std::reverse(newVec1.begin(), newVec1.end());
    	int max2 = maxProfit1(newVec1, start1, end1);

    	first = prices.begin();
		last = prices.begin() + start;
		vector<int> newVec2(first, last);
    	int max3 = maxProfit1(newVec2, start1, end1);

    	first = prices.begin() + end;
		last = prices.end();
		vector<int> newVec3(first, last);
    	int max4 = maxProfit1(newVec3, start1, end1);

        int max5 = max(max2, max3);
        return max1 + max(max4, max5);
    }
};

//my solution is too complicated

// public class Solution {
//     public int maxProfit(int[] prices) {
//         int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
//         int release1 = 0, release2 = 0;
//         for(int i:prices){                              // Assume we only have 0 money at first
//             release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
//             hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
//             release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
//             hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
//         }
//         return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
//     }
// }
