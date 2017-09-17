//bfs
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int> > loopQueue; 
        int sizeA = matrix.size();
        if( sizeA == 0 || matrix[0].size() == 0) {
        	return matrix;
        }
        int sizeB = matrix[0].size();
        for(int i = 0; i < sizeA; i ++) {
        	for(int j = 0; j < sizeB; j++) {
        		if(matrix[i][j] != 0) {
        			matrix[i][j] = INT_MAX;
        		} else {
        			loopQueue.emplace(pair<int, int>(i, j));
        		}
        	}
        }
        // cout<<"!!!"<<loopQueue.size()<<endl;

        while(loopQueue.size() != 0) {
        	pair<int, int> pos = loopQueue.front();
        	int level = matrix[pos.first][pos.second];
        	loopQueue.pop();
        	// cout<< loopQueue.size() << "~" << pos.first<<" " << pos.second<<"   " << matrix[pos.first][pos.second]<< endl;
        	for(int i = -1; i <= 1; i++) {
        		for(int j = -1; j <= 1; j++) {
        			int x = pos.first + i, y = pos.second + j;
        			if( (i == 0 && j == 0)  || x < 0 || x >= sizeA || y < 0 || y >= sizeB || i * j != 0) {
        				continue;
        			}
        			if(level+1 < matrix[x][y]) {
        				loopQueue.emplace(pair<int, int>(x, y));
        				matrix[x][y] = level+1;
        			}
        		}
        	}
        }
        
        return matrix;
    }
};


//dfs

