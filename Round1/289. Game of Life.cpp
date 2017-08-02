class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	for(int i = 0; i < board.size(); i++) {
    		for(int j = 0; j < board[i].size(); j++) {
    			int count = countNeighbour(board, i, j);
    			// cout<< i << "  " << j << "  " << count << endl;
    			if( ((count > 3 || count < 2) && board[i][j] == 1 )  || (count == 3 && board[i][j] == 0) ) {
    				board[i][j] = board[i][j] | 2;
    			}
    		}
    	}

    	for(int i = 0; i < board.size(); i++) {
    		for(int j = 0; j < board[i].size(); j++) {
    			if( (board[i][j] & 2) > 0) {
    				// cout << " !" << i << j << "  "<< board[i][j]  << "  " << (board[i][j] & 2)<<  endl;
    				board[i][j] = board[i][j] ^ 3;
    			}
    		}
    	}
    }

    int countNeighbour(vector<vector<int>>& board, int x, int y) {
    	vector<int> pos;
    	pos.emplace_back(-1);
    	pos.emplace_back(0);
    	pos.emplace_back(1);
    	int ret = 0;
    	for(int i = 0; i < 3; i ++) {
    		for(int j = 0; j < 3; j++) {
    			int x1 = x + pos[i], y1 = y + pos[j];
    			if(x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() && !(x1 == x && y1 == y)) {
    				ret += (board[x1][y1] & 1);
    			}
    		}
    	}
    	return ret;
    }
};