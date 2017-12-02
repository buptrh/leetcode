

int snapback(vector<int> values, vector<int> weights, int capacity) {
	vector<vector<int, int>> dp(capacity+1, vector<int>(items.size(), 0));
	for(int i = 0; i <= capacity; i++) {
		for(int j = 0; j < items.size(); j++) {
			dp[i][j] = max(dp[i][j], dp[i - weights[j]][j-1]);
		}
	}
}