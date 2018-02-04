class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> que;
        set<vector<vector<int>>> visited;
        int res = 0;
        que.push(board);
        while(!que.empty()) {
        	int size = que.size();
        	// cout<< res << endl;
        	for(int c = 0; c < size; c++) {
        		vector<vector<int>> b = que.front();
        		que.pop();
        		if(visited.count(b) != 0) {
        			continue;
        		}
        		outputVec(b);
        		visited.insert(b);
        		bool find = true;
        		for(int i = 0; i < board.size(); i++) {
        			for(int j = 0; j < board[0].size(); j++) {
        				int index = i*board[0].size() + j + 1;
        				// cout<<"index: " << index << "  " << b[i][j] <<endl; 
        				if(b[i][j] != index && !(b[i][j] == 0 && board.size() * board[0].size() == index)) {
        					find = false;
        				}
        				if(b[i][j] == 0) {
        					for(int x = -1; x <= 1; x++) {
        						for(int y = -1; y <= 1; y++) {
        							if(x+i < 0 || y+j < 0 || x+i >= board.size() || y+j >= board[0].size() || x * y != 0) {
        								continue;
        							}
        							vector<vector<int>> copy;
        							for(int m = 0; m < board.size(); m++) {
        								copy.push_back(vector<int>());
        								for(int n = 0; n < board[0].size(); n++) {
        									copy[m].push_back(b[m][n]);
        								}
        							}
        							swap(copy[i][j], copy[x+i][y+j]);
        							que.push(copy);
        						}
        					}
        					break;
        				}
        			}
        		}
        		if(find) {
        			return res;
        		}
        	}
        	res++;
        }
        return -1;
    }

   	void outputVec(vector<vector<int>>& board) {
   		return;
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				cout<<board[i][j] << "  ";
			}
		}
		cout<<endl;
   	}

};