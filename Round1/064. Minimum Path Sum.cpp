class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(); 
        if(row == 0) {
        	return 0;
        }
        int col = grid[0].size();
        if(col == 0) {
        	return 0;
        }

        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		if(i == 0 && j == 0) {
        			dp[i][j] = grid[i][j];
        		}
        		if(i >= 1) {
        			dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j]);
        		}
        		if(j >= 1) {
        			dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
        		}
        		// cout<<i <<". " << j << "  " << dp[i][j]<<endl;
        	}
        }
        return dp[row-1][col-1];
    }
};