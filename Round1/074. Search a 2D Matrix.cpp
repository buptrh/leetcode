// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row <= 0) {
        	return false;
        }
        int col = matrix[0].size();
        if(col <= 0) {
        	return false;
        }
        int count = row * col;
        int begin = 0, end = count-1, mid = 0;
        while(begin <= end) {
        	mid = begin + (end - begin)/2;
        	int i = mid / col;
        	int j = mid % col;
        	// cout<<begin << "  " << mid << "  " << end << "  |  " << i << "  " << j << endl;
        	if(matrix[i][j] == target) {
        		return true;
        	} else if (matrix[i][j] < target) {
        		begin = mid + 1;
        	} else {
        		end = mid - 1;
        	}
        }
        return false;
    }
};