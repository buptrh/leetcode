
int maxSize = 0;
int perfectSquare(int n, vector<vector<int>> & square) {
	if(n <= 0) {
		return false;
	}
	vector<vector<bool>>  check(n, vector<bool>(n, false));
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-1; j++) {
			if(square[i][j] + square[i+1][j+1] == square[i+1][j] + square[i][j+1]){
				check[i][j] = true;
			}
		}
	}
	helper(check, n-1, 0, 0);

	return maxSize;
}

bool helper(vector<vector<bool>> & check, int size, int x, int y) {
	if(size == 1) {
		maxSize = max(maxSize, 2);
		return check[x][y];
	}
	for(int i = x; i <= x+1; i++ ) {
		for(int j = y; j <= y+1; j++ ) {
			if(helper(check, size-1, i, j) == false) {
				return false;
			}
		}
	}
	maxSize = max(maxSize, size+1)
	return true;
}