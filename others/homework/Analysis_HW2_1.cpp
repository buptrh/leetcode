
int CollectApple(vector<vector<int>> & table) {
	int row = table.size();
	if(row == 0) {
		return 0;
	}
	int col = table[0].size();
	if(col == 0) {
		return 0;
	}
	vector<int> dp1(col, 0);
	vector<int> dp2(col, 0);
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(j > 0) {
				dp1[j] = dp1[j-1];
			}
			dp1[j] = max(dp1[j], dp2[j]);
			dp1[j] += table[i][j];
		}
		dp2 = dp1;
		dp1 = vector<int>(col, 0);
	}
	return dp2[col-1];
}