class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return res;
        }
        int row = matrix.size(), col = matrix[0].size();
        bool flag = true;
        for(int i = 0; i < row+col; i++) {
            for(int j = 0; j < row; j++) {
                int currentRow = j;
                if(flag) {
                    currentRow = row - j-1;
                }
                if(i-currentRow >= 0 && (i-currentRow) < col) {
                    res.push_back(matrix[currentRow][ i - currentRow]);
                }
            }
            flag = !flag;
        }
        return res;	
    }
};