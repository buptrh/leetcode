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
		int x = 0, y = col - 1;
		while(matrix[x][y] != target) {
			if(matrix[x][y] < target) {
				x++;
			} else {
				y--;
			}
			if(x >= row || y < 0) {
				return false;
			}
		}
		return true;
	}

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 	int row = matrix.size();
    // 	if(row == 0) {
    // 		return false;
    // 	}
    // 	int col = matrix[0].size();
    // 	if(col == 0) {
    // 		return false;
    // 	}
    // 	return helper(matrix, target, 0, 0, row-1, col-1);   
    // }

    bool helper(vector<vector<int>> & matrix, int target, int x1, int y1, int x2, int y2 ) {
    	// cout<<x1<< " " << y1 << " " << x2 << " " << y2<<endl;
    	if(x1 < 0 || x2 < 0 || x1 >= matrix.size() || x2 >= matrix.size()) {
    		return false;
    	}
    	if(y1 < 0 || y2 < 0 || y1 >= matrix[0].size() || y2 >= matrix[0].size()) {
    		return false;
    	}
    	int midX = x1 + (x2 - x1) / 2, midY = y1 + (y2 - y1) / 2;
    	if(x1 >= x2 && y1 >= y2) {
    		return (matrix[x1][y1] == target);
    	}
    	if(matrix[midX][midY] == target) {
    		return true;
    	} else if(matrix[midX][midY] > target) {
    		return helper(matrix, target, x1, y1, midX, midY) 
    			|| helper(matrix, target, midX+1, y1, x2, midY) 
    			|| helper(matrix, target, x1, midY+1, midX, y2);
    	} else {
    		return helper(matrix, target, midX+1, midY+1, x2, y2) 
    			|| helper(matrix, target, midX+1, y1, x2, midY) 
    			|| helper(matrix, target, x1, midY+1, midX, y2);

    	}

    }
};