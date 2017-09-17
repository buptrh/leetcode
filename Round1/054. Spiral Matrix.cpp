class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ret;
        int col = matrix.size();
        if(col == 0) {
        	return ret;
        }
        int row = matrix[0].size();
        if(row == 0) {
        	return ret;
        }
        int count = row * col;
        int left = 0, right = col-1, top = 0, bottom = row-1, i = 0, j = 0;
        int towardi = (left == right ? 0, 1), towardj = (left == right ? 1, 0);
        while(count > 0) {
        	ret.emplace_back(matrix[i][j]);
        	count--;
        	if(count == 0) {
        		break;
        	}
    		i += towardi;
    		j += towardj;
    		if( i == )
        }
        return ret;
    }
};