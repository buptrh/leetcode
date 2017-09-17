class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
    	int row = M.size();
    	if(row <= 0) {
    		return 0;
    	}
    	int ret = 0;
    	queue<pair<int, int> > traversal;
        for(int i = 0; i < row; i++) {
        	// cout<<"!!" ;
        	bool add = false;
        	for(int j = 0; j < row; j++) {
        		if(M[i][j] == 1) {
        			traversal.emplace(pair<int, int>(i,j));
        			// cout<<"("<<i<<" " << j << "). ";
        			M[i][j] = 0;
        			M[j][i] = 0;
        			add = true;
        		}
        	}

        	while(traversal.size() > 0) {
        		pair<int, int> pos = traversal.front(); 
        		traversal.pop();
        		for(int m = 0; m < row; m++) {
        			int j = pos.second;
        			if(M[j][m] == 1) {
        				// cout<<"("<<j<<" " << m << "). ";
        				traversal.emplace(pair<int, int>(j, m));
	        			M[j][m] = 0;
	        			M[m][j] = 0;
	        			add = true;
        			}
        		}
        	}
        	if(add) {
        		ret++;
        	}
        }
        return ret;
    }
};

//could be quicker. because if i is visited, in this solution still need to go j.
// better solution is to define a visited array to record if a person is visited.