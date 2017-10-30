#include <iostream>
#include <vector>
using namespace std;

int ChangeCoinsGreedy(vector<int> & prices, int val) {
	int ret = 0;
	for(int i = prices.size()-1; i >= 0; i--) {
		ret += val/prices[i];
		val = val % prices[i];
	}
	return ret;
}

int ChangeCoinsDP(vector<int> & prices, int val) {
    vector<int> dp(val+1, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i <= val; i++){
		for(int j = 0; j < prices.size(); j++) {
			if(i-prices[j] < 0) {
				break;
			}
			dp[i] = min(dp[i], dp[i-prices[j]]+1);
		}
	}
	return dp[val];
}


int main() {
	vector<int> prices{1, 4, 7, 13, 28, 52, 91, 365};
    //reverse(prices.begin(), prices.end());
	int val = 0;
    cout<<ChangeCoinsDP(prices, 455);
	return 0;
}