class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    	int row = matrix.size();
    	if( row == 0) {
    		return true;
    	}
    	int col = matrix[0].size();
    	if(col == 0) {
    		return true;
    	}
        for(int i = -col; i <= col; i++) {
        	bool inited = false;
        	int val = 0;
        	for(int j = 0; j < row; j++) {
        		if(i+j < 0 || i+j >= col) {
        			continue;
        		}
        		if(!inited) {
        			val = matrix[j][i+j];
        			inited = true;
        		}
        		// cout << j << "  " << i+j << "  " << val << "  " << matrix[j][i+j] << endl;
        		if(matrix[j][i+j] != val) {
        			return false;
        		}
        	}
        	// cout<<"!!" << endl;
        }
        return true;
    }
};