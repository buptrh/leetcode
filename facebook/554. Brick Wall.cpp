class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> table;
        int maxval = 0;
        for(int i = 0; i < wall.size(); i++) {
        	int sum = 0;
        	for(int j = 0; j < wall[i].size()-1; j++) {
        		sum += wall[i][j];
        		table[sum]++;
    			maxval = max(maxval, table[sum]);
        	}
        }
        return wall.size() - maxval;
    }
};