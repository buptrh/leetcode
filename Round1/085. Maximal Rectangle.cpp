class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) {
        	return 0;
        }
        int col = matrix[0].size();
        if(col == 0) {
        	return 0;
        }
        vector<int> height(col+1, 0);
        int max_area = 0;
        for(int i = 0; i < row; i++) {
        	stack<pair<int, int>> sta;
        	for(int j = 0; j <= col; j++) {
        		if(j < col) {
        			if(matrix[i][j] == '1') {
        				height[j]++;
        			} else {
        				height[j] = 0;
        			}
        		}
        		int preIndex = j;
        		while(sta.size() != 0 && sta.top().second > height[j]) {
	        		preIndex = sta.top().first;
	        		max_area = max(max_area, sta.top().second * (j - sta.top().first));
	        		sta.pop();
	        	}
	        	sta.push(pair<int, int>(preIndex, height[j]));
        	}
        }
        return max_area;
    }
};