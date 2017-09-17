class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int row = matrix.size();
    	if(row == 0) {
    		return false;
    	}
    	int col = matrix[0].size();
    	if(col == 0) {
    		return false;
    	}
        int start = 0, end = row * col - 1, mid, x, y;
        while(start + 1 < end) {
        	mid = start + (end - start) / 2;
        	x = mid / col;
        	y = mid % col;
        	if(matrix[x][y] == target) {
        		return true;
        	} else if(matrix[x][y] < target) {
        		start = mid;
        	} else {
        		end = mid;
        	}
        }

        // cout<< start << "   " << end;

    	x = start / col;
    	y = start % col;
    	if(matrix[x][y] == target) {
    		return true;
    	}

    	x = end / col;
    	y = end % col;
    	if(matrix[x][y] == target) {
    		return true;
    	}

    	return false;

    }
};