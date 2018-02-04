

// 0 1 0
// 1 0 1
// 0 1 0
// return 3
int maximumSquare(vector<vector<int>> & matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col, 1));
	for(int i = 1; i < row; i++) {
		for(int j = 1; j < col; j++) {
			if(matrix[i][j] == matrix[i-1][j-1] 
				&& matrix[i][j] != matrix[i-1][j] 
				&& matrix[i][j] != matrix[i][j-1]) {
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
				dp[i][j] = min(dp[i][j], dp[i][j-1]);
				dp[i][j]++;
			} else {
				dp[i][j] = 1;
			}
		}
	}
	return dp[row-1][col-1];
}

