
int maximalSquare(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if(row == 0) {
        return 0;
    }
    int col = matrix[0].size();
    if(col == 0) {
        return 0;
    }
    int max_len = 0;
    //dp[x][y] means length of maximum square from (x-1, y-1) to topleft;
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    for(int i = 1; i <= row; i++) { 
        for(int j = 1; j <= col; j++) {
            if(matrix[i-1][j-1] == 0) {
                continue;
            }
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            max_len = max(max_len, dp[i][j]);
        }
    }
    return max_len * max_len;
}
