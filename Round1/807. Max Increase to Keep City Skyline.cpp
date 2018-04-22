class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.size() == 0 || grid[0].size() == 0) {
        	return res;
        }
        vector<int> up(grid[0].size(), 0), left(grid.size(), 0);
        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid.size(); j++) {
        		up[j] = max(up[j], grid[i][j]);
        		left[i] = max(left[i], grid[i][j]);
        	}
        }

        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid.size(); j++) {
        		res += min(up[j] - grid[i][j], left[i] - grid[i][j]);
        	}
        }
        return res;
    }
};