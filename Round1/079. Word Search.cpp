class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.size() == 0) {
    		return true;
    	}
    	if(board.size() == 0 || board[0].size() == 0) {
    		return false;
    	} 
        for(int i = 0; i < board.size(); i++) {
        	for(int j = 0; j < board[0].size(); j++) {
        		if(board[i][j] == word[0]) {
    				board[i][j] = '?';
        			bool flag = helper(board, word, 1, i, j);
        			if(flag) {
        				return true;
        			}
        			board[i][j] = word[0];
        		}
        	}
        }
        return false;
    }

    bool helper(vector<vector<char>> & board, string word, int pos, int x, int y) {
    	if(pos == word.size()) {
    		return true;
    	}
    	for(int i = x-1; i <= x+1; i++) {
    		for(int j = y-1; j <= y+1; j++) {
    			if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || (i != x && j != y)) {
    				continue;
    			}
    			if(word[pos] == board[i][j]) {
    				board[i][j] = '?';
        			bool flag = helper(board, word, pos+1, i, j);
        			if(flag) {
        				return true;
        			}
        			board[i][j] = word[pos];
    			}
    		}
    	}
    	return false;
    }
};