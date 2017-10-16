
vector<pair<int, int>> movingOnGrid(vector<vector<int>> & matrix) {
	vector<pair<int, int>> ret;
	int row = matrix.size();
	if(row == 0) {
		return ret;
	}
	int col = matrix[0].size();
	if(col == 0) {
		return ret;
	}
	vector<int> dp1(col+1, 0);
	vector<int> dp2(col+1, 0);
	vector<vector<pair<int, int>>> path1 = vector<vector<pair<int, int>>>(col+1, vector<pair<int, int>>());
	vector<vector<pair<int, int>>> path2 = vector<vector<pair<int, int>>>(col+1, vector<pair<int, int>>());
	int minSum = INT_MAX;
	for(int i = 1; i <= row; i++) {
		int minVal = INT_MAX, minIndex = 0;
		for(int j = 1; j <= col; j++) {
			if(j >= 2) {
				minVal = dp2[j-1];
				minIndex = j-1;
			}
			if(minVal > dp2[j]) {
				minVal = dp2[j];
				minIndex = j;
			}
			if(j < col && minVal > dp2[j+1]){
				minVal = dp2[j+1];
				minIndex = j+1;
			}
			dp1[j] = minVal + matrix[i-1][j-1];
			path1[j] = path2[minIndex];
			if(i != 1) {
				path1[j].emplace_back(pair<int, int>(i-1, minIndex));
			}
			if(i == row && minSum > dp1[j]) {
				minSum = dp1[j];
				path1[j].emplace_back(i, j);
				ret = path1[j];
			}
		}
		dp2 = dp1;
		dp1 = vector<int>(col, 0);
		path2 = path1;
		path1 = vector<vector<pair<int, int>>>(col+1, vector<pair<int, int>>());
	}
	return ret;
}