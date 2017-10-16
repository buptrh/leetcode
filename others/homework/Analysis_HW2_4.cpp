int CardGame(vector<int> & nums) {
	//add x, y by 2, so that I can have some extra space to ignore edge cases.
	//dp[i][j] means maximum sum from i-th card to (j-2)-th card.
	vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));

	for(int len = 0; len < nums.size(); len++) {
		for(int i = 0; i < nums.size(); i++) {
			int j = i + len + 2;//offset all j by 2, so that I don't need to check if j-2 is greater than 0
			if(j-2 >= nums.size()) {
				break;
			}
			dp[i][j] = max(nums[i] + min(dp[i+2][j], dp[i+1][j-1]), 
							nums[j-2] + min(dp[i+1][j-1], dp[i][j-2]));
		}
	}

	return dp[0][nums.size()+1];//because j is offset by 2, so return value should add 2.
}
