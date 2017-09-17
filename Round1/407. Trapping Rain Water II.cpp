class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<vector<int>>> dp(heightMap.size(), vector<vector<int>>(heightMap[0].size(), vector<int>(5, -1)));
        int ret = 0;
        for(int i = 0; i < heightMap.size(); i++) {
        	for(int j = 0; j < heightMap[0].size; j++) {
        		helper(heightMap, dp, i, j, 0);
        		if(dp[i][j][0] > heightMap[i][j]) {
        			ret += dp[i][j][0] > heightMap[i][j];
        		}
        	}
        }
        return ret;
    }

    //all 0, top 1, bottom 2, left 3, right 4; 
    void helper(vector<vector<int>>& heightMap, vector<vector<vector<int>>> & dp, int x, int y, int from) {
		if(dp[x][y] >= 0) {
			return dp[x][y];
		}

    	if(from == 0) {
    		int t1 = min(helper(heightMap, dp, x, y, 1), helper(heightMap, dp, x, y, 2));
    		int t2 = min(helper(heightMap, dp, x, y, 3), helper(heightMap, dp, x, y, 4));
    		dp[x][y][0] = min(t1, t2);
    	} else {
    		if(dp[x][y][from] >= 0) {
    			return dp[x][y][from];
    		}

    		
    	}
    }
};