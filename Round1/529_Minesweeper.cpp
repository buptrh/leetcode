class Solution {
public:
	int findAdjacentMines(vector<vector<char>>& board, int x, int y) {
		int count = 0;
		for(int i = -1; i <= 1; i++) {
			for(int j = -1; j <= 1; j++) {
				if( (i == 0 && j == 0) || x+i < 0 || y+j < 0 || x+i >= board.size() || y+j >= board[0].size() || board[x+i][y+j] != 'M') {
        			continue;
        		}
        		count++;
			}
		}
		return count;
	}

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        std::vector< vector<char> > vRet(board);
        if(board.size() == 0 || board[0].size() == 0) {
        	return vRet;
        }
        char clicked = board[click[0]][click[1]];
        if( clicked == 'M' ){
        	vRet[click[0]][click[1]] = 'X';
        	return vRet;
        } else {
        	queue< pair<int, int> > blank;
        	blank.emplace(pair<int, int>(click[0], click[1]));
        	while(blank.size() > 0) {
        		pair<int, int> front = blank.front();
        		blank.pop();
        		if(front.first < 0 || front.second < 0 || front.first >= board.size() || front.second >= board[0].size() || vRet[front.first][front.second] != 'E') {
        			continue;
        		}
        		int mines = findAdjacentMines(vRet, front.first, front.second);
        		if(mines == 0) {
        			vRet[front.first][front.second] = 'B';
        			for(int i = -1; i <= 1; i++) {
        				for(int j = -1; j <= 1; j++) {
        					if(i != 0 || j != 0) {
        						blank.emplace(pair<int, int>(front.first+i, front.second+j));
        					}
        				}
        			}
        		} else {
        			vRet[front.first][front.second] = '0' + mines;
        		}
        	} 
        }

        return vRet;
    }
};


