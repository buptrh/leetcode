class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int row = matrix.size(); 
    	if(row == 0) {
    		return;
    	}
    	int col = matrix[0].size();
    	bool setRow0 = false;
        for(int i = 0; i < row; i++) {
        	if(matrix[i][0] == 0) {
        		setRow0 = true;
        	}
        	for(int j = 1; j < col; j++) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = matrix[0][j] = 0;
        		}
        	}
        }
        for(int i = row-1; i >= 0; i--) {
        	for(int j = col-1; j >= 1; j--) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;
        		}
        	}
        	if(setRow0) {
        		matrix[i][0] = 0;
        	}
        }
    }
};