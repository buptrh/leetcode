class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int row = grid.size();
    	if(row <= 0) {
    		return 0;
    	}
    	int col = grid[0].size();
    	if(col <= 0) {
    		return 0;
    	}
    	int count = 0;
    	queue<pair<int, int> > island;
        for(int i = 0; i < row; i++) {
        	for(int j = 0; j < col; j++) {
        		if(grid[i][j] != '1'  ) {
        			continue;
        		}

        		island.emplace(pair<int, int>(i,j));

        		while(island.size() > 0) {
        			pair<int, int> pos = island.front();
        			int x = pos.first, y = pos.second;
        			island.pop();

		    		if(grid[x][y] != '1'  ) {
		    			continue;
		    		}
        			grid[x][y] = '2';
        			if( x > 0 && grid[x-1][y] == '1') 
    				{
        				island.emplace(pair<int, int>(x-1, y));
    				}

        			if( y > 0 && grid[x][y-1] == '1') 
    				{
        				island.emplace(pair<int, int>(x, y-1));
    				}

        			if( x+1 < row && grid[x+1][y] == '1') 
    				{
        				island.emplace(pair<int, int>(x+1, y));
    				}

        			if( y+1 < col && grid[x][y+1] == '1') 
    				{
        				island.emplace(pair<int, int>(x, y+1));
    				}	

        		}

        		count++;
        	}
        }
        return count;
    }
};