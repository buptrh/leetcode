class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
    	int row = grid.size(); 
    	if(row == 0) {
    		return 0;
    	}
    	int col = grid[0].size();
    	if(col == 0) {
    		return 0;
    	}
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int res = 0;
        for(int i = 0; i < row; i++) {
        	int v = 0;
        	for(int j = 0; j < col; j++) {
        		if(grid[i][j] == 'E') {
        			v++;
        		} else if(grid[i][j] == 'W') {
        			v = 0;
        		} else {
        			dp[i][j] += v;
        		}
        	}
        	v = 0;
        	for(int j = col - 1; j >= 0; j--) {
        		if(grid[i][j] == 'E') {
        			v++;
        		} else if(grid[i][j] == 'W') {
        			v = 0;
        		} else {
        			dp[i][j] += v;
        		}
        	}
        }
        for(int j = 0; j < col; j++) {
        	int v = 0;
        	for(int i = 0; i < row; i++) {
        		if(grid[i][j] == 'E') {
        			v++;
        		} else if(grid[i][j] == 'W') {
        			v = 0;
        		} else {
        			dp[i][j] += v;
        		}
        	}
        	v = 0;
        	for(int i = row - 1; i >= 0; i--) {
        		if(grid[i][j] == 'E') {
        			v++;
        		} else if(grid[i][j] == 'W') {
        			v = 0;
        		} else {
        			dp[i][j] += v;
        		}
        	}
        	res = max(res, dp[i][j]);
        }
        return res;
    }
};