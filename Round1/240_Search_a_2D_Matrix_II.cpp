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
        for(int i = 0; i < row; i++) {
        	if(matrix[i][0] == target || matrix[i][col-1] == target  ) {
        		return true;
        	} else if(matrix[i][0] > target) {
        		return false;
        	} else if(matrix[i][col-1] < target) {
        		continue;
        	}
        	bool ret = checkInRow(matrix, target, i, 0, col-1);
        	if(ret) {
        		return true;
        	}
        }
        return false;
    }
    bool checkInRow(vector<vector<int>>& matrix, int target, int pos, int minPos, int maxPos) {
    	int index = 0;
        	// cout<<"checkRow" << "  "<<pos<<". " << minPos<< "  " << maxPos<<endl;
		if(minPos == maxPos) {
			return (matrix[pos][minPos] == target);
		}
    	while(maxPos > minPos) {
        	index = (maxPos-minPos)/2 + minPos;
    		if(matrix[pos][index] > target) {
        		maxPos = index;
        		if(minPos == index){
        			return false;
        		}
        	} else if(matrix[pos][index] < target) {
        		if(minPos == index){
        			// cout<<"~~~~~" << index<< " " << maxPos << " " <<matrix[index][maxPos]<<endl;
        			return (matrix[pos][maxPos] == target);
        		}
        		minPos = index;
        	} else {
        		return true;
        	}
        	// cout<<"checkRow222" << index<< "  "<<pos<<". " << minPos<< "  " << maxPos<<endl;
    	}
        return false;
    }
};


// another o(m+n) solution :start from top right, calculate to decide go left or go down