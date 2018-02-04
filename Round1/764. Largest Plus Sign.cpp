class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dpUp(N+1, vector<int>(N+1, 0));
        vector<vector<int>> dpDown(N+2, vector<int>(N+2, 0));
        vector<vector<int>> dpRight(N+2, vector<int>(N+2, 0));
        vector<vector<int>> dpLeft(N+2, vector<int>(N+2, 0));

        vector<vector<int>> table(N, vector<int>(N, 1));

        for(vector<int> mine : mines) {
        	table[mine[0]][mine[1]] = 0;
        }

        for(int i = 0; i < N; i++) {
        	for(int j = 0; j < N; j++) {
        		if(table[i][j] == 0) {
        			dpUp[i+1][j+1] = 0;
        			dpLeft[i+1][j+1] = 0;
        		} else {
        			dpUp[i+1][j+1] = dpUp[i][j+1] + 1;
        			dpLeft[i+1][j+1] = dpLeft[i+1][j] + 1;
        		}
        	}
        }
        int res = 0;
        for(int i = N-1; i >= 0; i--) {
        	for(int j = N-1; j >= 0; j--) {
        		if(table[i][j] == 0) {
        			dpRight[i+1][j+1] = 0;
        			dpDown[i+1][j+1] = 0;
        		} else {
        			dpDown[i+1][j+1] = dpDown[i+2][j+1] + 1;
        			dpRight[i+1][j+1] = dpRight[i+1][j+2] + 1;
        			int len = min(min(dpUp[i+1][j+1], dpLeft[i+1][j+1]) , min(dpRight[i+1][j+1], dpDown[i+1][j+1]));
        			res = max(res, len);
        		}
        		cout<< i << "  " << j << " :  "  << dpUp[i+1][j+1] << "  " << dpDown[i+1][j+1]<< "  " << dpLeft[i+1][j+1] << "  " << dpRight[i+1][j+1]<< endl;
        	}
        }
        return res;
    }
};