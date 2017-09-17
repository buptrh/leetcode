class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    	int ret = 0;
    	int row = grid.size();
    	if(row == 0) {
    		return ret;
    	}
    	int col = grid[0].size();
    	// cout << row << "  " << col << endl;
        for(int i = 0; i < row; i++) {
        	for(int j = 0; j < col; j++) {
        		if(grid[i][j] == 1) {
        			// cout << i << "  " << j << endl;
        			if(i == 0 || grid[i-1][j] == 0) {
        				ret++;
        			}
        			if(j == 0 || grid[i][j-1] == 0) {
        				ret++;
        			}
        			if(i == row-1 || grid[i+1][j] == 0) {
        				ret++;
        			}
        			if(j == col-1 || grid[i][j+1] == 0) {
        				ret++;
        			}
        		}
        	}
        }
        return ret;
    }
};