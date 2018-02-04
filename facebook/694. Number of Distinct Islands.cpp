class Solution {
public:
	int row, col;
    int numDistinctIslands(vector<vector<int>>& grid) {
    	row = grid.size();
    	if(row == 0) {
    		return 0;
    	}
    	col = grid[0].size();
    	if(col == 0) {
    		return 0;
    	}
    	set<set<pair<int, int>>> res;
    	unordered_set<int> visited;
    	for(int i = 0; i < row; i++) {
    		for(int j = 0; j < col; j++) {
    			int pos = getIndex(i, j);
    			if(grid[i][j] == 1 && visited.find(pos) == visited.end()) {
    				// cout<<"try: " << pos << endl;
    				unordered_set<int> path;
    				dfs(grid, path, visited, i, j);
    				int x = (*path.begin()) / col;
    				int y = (*path.begin()) % col;
    				set<pair<int, int>> island;
    				for(int index : path) {
	    				int m = index / col;
	    				int n = index % col;
	    				// cout<<m << "  " << n << endl;
	    				island.insert(make_pair(m-x, n-y));
    				}
    				res.insert(island);
    			}
    		}
    	}
    	return res.size();
    }

    int getIndex(int x, int y) {
    	return x*col + y;
    }

    void dfs(vector<vector<int>>& grid, unordered_set<int>& path, unordered_set<int> & visited, int x, int y) {
    	int index = getIndex(x, y);
    	if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0 || visited.find(index) != visited.end()) {
    		return;
    	}
    	visited.insert(index);
    	path.insert(index);
    	dfs(grid, path, visited, x+1, y);
    	dfs(grid, path, visited, x-1, y);
    	dfs(grid, path, visited, x, y+1);
    	dfs(grid, path, visited, x, y-1);
    }
};