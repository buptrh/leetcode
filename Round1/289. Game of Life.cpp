//01 dead - alive
//00 dead - dead
//11 alive - alive
//10 alive - dead

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) {
        	return;
        }

        for(int i = 0; i < board.size(); i++) {
        	for(int j = 0; j < board[0].size(); j++) {
        		int count = liveNeighbors(i, j, board);
        		int val = board[i][j];
        		if((val == 1 && count == 2) || count == 3) {
        			board[i][j] |= 2;
        		} else {
        			board[i][j] &= 1;
        		}
        	}
        }

        for(int i = 0; i < board.size(); i++) {
        	for(int j = 0; j < board[0].size(); j++) {
        		board[i][j] = board[i][j]>>1;
       		}
   		}
    }

    int liveNeighbors(int x, int y, vector<vector<int>>& board) {
    	int count = 0;
    	for(int i = -1; i <= 1; i++) {
    		for(int j = -1; j <= 1; j++) {
    			if((i == 0 && j == 0) || x+i < 0 || y+j < 0 || x+i >= board.size() || y+j >= board[0].size()) {
    				continue;
    			}
    			if(board[x+i][y+j] & 1 == 1) {
    				count++;
    			}
    		}
    	}
    	return count;
    }
};