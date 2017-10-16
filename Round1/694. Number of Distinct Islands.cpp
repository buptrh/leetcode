class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size(); 
        if(row == 0) {
        	return 0;
        }
        int col = grid[0].size();
        if(col == 0) {
        	return 0;
        }
        set<set<pair<int, int>>> islands;
        for(int i = 0; i < row; i ++) {
        	for(int j = 0; j < col; j++) {
        		if(grid[i][j] == 1) {
        			set<pair<int, int>> island;
        			queue<pair<int, int>> que;
        			que.push(pair<int, int>(i, j));
        			while(que.size() != 0) {
        				int x = que.front().first;
        				int y = que.front().second;
        				que.pop();
        				if(grid[x][y] == 1) {
        					island.insert(pair<int, int>(x-i, y-j));
        					grid[x][y] = 0;
        					if(x > 0) {
        						que.emplace(pair<int, int>(x-1, y));
        					}
    						if(y > 0) {
    							que.emplace(pair<int, int>(x, y-1));
    						}
    						if(x < row-1) {
        						que.emplace(pair<int, int>(x+1, y));
    						}
    						if(y < col-1) {
        						que.emplace(pair<int, int>(x, y+1));
    						}
        				}
        			}
        			islands.insert(island);
        		}

        	}
        }
        return islands.size();
    }
};
//11:25