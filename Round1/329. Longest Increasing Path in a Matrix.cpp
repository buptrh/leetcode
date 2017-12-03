class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0 || matrix[0].size() == 0) {
    		return 0;
    	}
    	vector<pair<int, int> > table;
    	for(int i = 0; i < matrix.size(); i++) {
    		for(int j = 0; j < matrix[0].size(); j++ ) {
    			table.push_back(pair<int, int>(i,j));
    		}
    	}
        auto comp = [&matrix](pair<int, int> a, pair<int, int> b) {
		    return matrix[a.first][a.second] < matrix[b.first][b.second];
		};
		sort(table.begin(), table.end(), comp);
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
		int ret = 0;
		for(int i = 0; i < table.size(); i++) {
			int x = table[i].first;
			int y = table[i].second;
			for(int m = -1; m <= 1; m ++) {
				for(int n = -1; n <= 1; n ++) {
					if(m * n != 0) {
						continue;
					}
					if(m+x >= 0 && n+y >= 0 && m+x < matrix.size() && n+y < matrix[0].size() && matrix[m+x][n+y] < matrix[x][y]) {
						dp[x][y] = max(dp[x][y], dp[m+x][n+y]+1);
					}
				}
			}
			// cout<< "dp" << x << "  " << y << " : "<< matrix[x][y] << "  " << dp[x][y]<<endl;
 			ret = max(ret, dp[x][y]);
		}
		return ret;
    }
};