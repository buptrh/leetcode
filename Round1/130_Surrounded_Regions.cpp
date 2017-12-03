class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int arr[] = {0, -1, 0, 1, 0};
        int row = board.size();
        if(row == 0) {
        	return;
        }
        int col = board[0].size();
        if(col == 0) {
        	return;
        }

        queue<pair<int, int> > zeros;
        for(int i = 0; i < row; i++) {
        	if(board[i][0] == 'O') {
        		zeros.emplace(pair<int, int>(i, 0));
        	}
        	if(col-1 != 0 && board[i][col-1] == 'O') {
        		zeros.emplace(pair<int, int>(i, col-1));
        	}
        }
        for(int i = 0; i < col; i++) {
        	if(i != 0 && i != col-1 && board[0][i] == 'O') {
        		zeros.emplace(pair<int, int>(0, i));
        	}
        	if(i != 0 && i != col-1 && board[row-1][i] == 'O') {
        		zeros.emplace(pair<int, int>(row-1, i));
        	}
        }
        // cout<<zeros.size()<<endl;
        while(zeros.size() > 0) {
        	pair<int, int> pos = zeros.front();
        	zeros.pop();
        	// cout<<pos.first<<". "<<pos.second<<endl;
        	board[pos.first][pos.second] = 'A';
        	for(int i = 0; i < 4; i ++) {
    			int x = pos.first + arr[i],  y = pos.second + arr[i+1];
    			// cout<<"test:"<< x<<" "<<y<<endl;
    			if(x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O') {
    				zeros.emplace(pair<int, int>(x,y));
    			}
        	}
        }
        for(int i = 0; i < row; i ++) {
        	for(int j = 0; j < col; j++) {
        		if(board[i][j] == 'A') {
        			board[i][j] = 'O';
        		} else if(board[i][j] == 'O') {
        			board[i][j] = 'X';
        		}
        	}
        }
    }
};