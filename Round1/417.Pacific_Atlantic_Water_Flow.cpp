class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	int row = matrix.size();
    	 vector<pair<int, int>> ret;
    	if(row == 0) { 
    		return ret;
    	}
    	int col = matrix[0].size();
    	if(row == 0) { 
    		return ret;
    	}

        vector< vector<bool> > pMatrix;
        vector< vector<bool> > aMatrix;
        for(int i = 0; i < row; i ++) {
        	vector<bool> vec;
        	for(int j = 0; j < col; j++) {
        		vec.emplace_back(false);
        	}
        	pMatrix.emplace_back(vec);
        	aMatrix.emplace_back(vec);
        }
        queue< pair<int, int> > pacific, atlantic;
        for(int i = 0; i < row; i++) {
        	pacific.push(pair<int, int>(i,0) ) ;
        	pMatrix[i][0] = true;
        	atlantic.push(pair<int, int>(i, col-1) );
        	aMatrix[i][col-1] = true;
        }
        for(int i = 0; i < col; i++) {
        	pacific.push(pair<int, int>(0,i) ) ;
        	pMatrix[0][i] = true;
        	atlantic.push(pair<int, int>(row-1, i) );
        	aMatrix[row-1][i] = true;
        }

        while(pacific.size() > 0) {
        	pair<int, int> top = pacific.front();
        	pacific.pop();
        	if(top.first > 0 && top.second > 0 && !pMatrix[top.first-1][top.second] && matrix[top.first][top.second] <= matrix[top.first-1][top.second]) {
        		pacific.emplace(pair<int, int>(top.first-1, top.second));
        		pMatrix[top.first-1][top.second] = true;
        	}
        	if(top.first+1 < row && !pMatrix[top.first+1][top.second] && matrix[top.first][top.second] <= matrix[top.first+1][top.second]) {
        		pacific.emplace(pair<int, int>(top.first+1, top.second));
        		pMatrix[top.first+1][top.second] = true;
        	}
        	if(top.second > 0 && !pMatrix[top.first][top.second-1] && matrix[top.first][top.second] <= matrix[top.first][top.second-1]) {
        		pacific.emplace(pair<int, int>(top.first, top.second-1));
        		pMatrix[top.first][top.second-1] = true;
        	}
        	if(top.second+1 < col && !pMatrix[top.first][top.second+1] && matrix[top.first][top.second] <= matrix[top.first][top.second+1]) {
        		pacific.emplace(pair<int, int>(top.first, top.second+1));
        		pMatrix[top.first][top.second+1] = true;
        	}
        }

        while(atlantic.size() > 0) {
        	pair<int, int> top = atlantic.front();
        	atlantic.pop();
        	if(top.first > 0 && !aMatrix[top.first-1][top.second] && matrix[top.first][top.second] <= matrix[top.first-1][top.second]) {
        		atlantic.emplace(pair<int, int>(top.first-1, top.second));
        		aMatrix[top.first-1][top.second] = true;
        	}
        	if(top.first+1 < row && !aMatrix[top.first+1][top.second] && matrix[top.first][top.second] <= matrix[top.first+1][top.second]) {
        		atlantic.emplace(pair<int, int>(top.first+1, top.second));
        		aMatrix[top.first+1][top.second] = true;
        	}
        	if(top.second > 0 && !aMatrix[top.first][top.second-1] && matrix[top.first][top.second] <= matrix[top.first][top.second-1]) {
        		atlantic.emplace(pair<int, int>(top.first, top.second-1));
        		aMatrix[top.first][top.second-1] = true;
        	}
        	if(top.second+1 < col && !aMatrix[top.first][top.second+1] && matrix[top.first][top.second] <= matrix[top.first][top.second+1]) {
        		atlantic.emplace(pair<int, int>(top.first, top.second+1));
        		aMatrix[top.first][top.second+1] = true;
        	}
        }

        for(int i = 0; i < row; i++) {
        	for(int j = 0; j < col; j++) {
        		if(pMatrix[i][j] && aMatrix[i][j]) {
        			pair<int, int> p(i,j);
        			ret.emplace_back(p);
        		}
        	}
        }

        return ret;
    }
};

//pay attention to BFS and DFS



