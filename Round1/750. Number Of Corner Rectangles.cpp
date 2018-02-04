class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
    	int res = 0;
        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid[0].size(); j++) {
        		if(grid[i][j] != 1) {
        			continue;
        		}
        		for(int x = i+1; x < grid.size(); x++) {
        			for(int y = j+1; y < grid[0].size(); y++) {
        				if( grid[i][y] != 1 || grid[x][j] != 1 || grid[x][y] != 1) {
        					continue;
        				}
    					res++;
        			}
        		}
        	}
        }
        return res;
    }

};