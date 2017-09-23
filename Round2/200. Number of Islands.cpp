class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int row = grid.size();
    	if(row == 0) {
    		return 0;
    	}
    	int col = grid[0].size();
    	if(col == 0) {
    		return 0;
    	}

    	int ret = 0;
    	queue<pair<int, int>> que;
    	vector<int> a = {0, 0, 1, -1}, b = {-1, 1, 0, 0};
    	for(int i = 0; i < row; i ++) {
    		for(int j = 0; j < col; j++) {
    			if(grid[i][j] == '1') {
    				ret++;
    				// cout<<"add "<< i << "  " << j<<endl;
    				que.push(pair<int, int>(i, j));
    				while(!que.empty()) {
    					int m = que.front().first;
    					int n = que.front().second;
    					que.pop();
    					if(grid[m][n] == '1') {
							// cout<<" "<< m << "  " << n <<". " << grid[m][n] <<endl;
							grid[m][n] = '0';
	    					for(int x = 0; x < a.size(); x++) {
	    						if(m + a[x] < 0 || m + a[x] >= row || n + b[x] < 0 || n + b[x] >= col) {
	    							continue;
	    						}
	    						que.push(pair<int, int>(m + a[x], n + b[x]));
		    				}
    					}
    				}
    			}
    		}
    	}

    	return ret;
    }
};