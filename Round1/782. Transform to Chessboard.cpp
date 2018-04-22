class Solution {
public:

    int movesToChessboard(vector<vector<int>>& board) {
    	int res = 0;
    	bool flag = false;
    	int item = board[0][0];
    	output(board);
    	cout<<"init"<<endl;
    	if(board.size() % 2 != 0) {

	    	int count = 0;
	    	for(int i = 0; i < board.size(); i++) {
	    		if(board[i][0] == 0) {
	    			count ++;
	    		}     	
	    	}

	    	if(count > board.size()/2) {
	    		item = 0;
	    	} else {
	    		item = 1;
	    	}
    	}
		for(int i = 0; i < board.size(); i++) {
			if(board[i][0] == (i%2) == 0 ? item : (item+1)%2) {
				continue;
			}
			flag = false;
			for(int j = i+1; j < board.size(); j++) {
				if(i%2 == j%2) {
					continue;
				}
				if(board[j][0] != board[i][0]) {
					for(int m = 0; m < board.size(); m++) {
						swap(board[i][m], board[j][m]);
					}
					res++;
					flag = true;
					break;
				}
			}
			if(!flag) {
				cout<<"false"<<endl;
				return -1;
			}
		}
		output(board);
		cout<<"test: " << res <<endl;

		
    	if(board.size() % 2 != 0) {

	    	int count = 0;
	    	for(int i = 0; i < board.size(); i++) {
	    		if(board[0][i] == 0) {
	    			count ++;
	    		}     	
	    	}

	    	if(count > board.size()/2) {
	    		item = 0;
	    	} else {
	    		item = 1;
	    	}
    	}
		for(int i = 0; i < board.size(); i++) {
			if(board[0][i] == (i%2) == 0 ? item : (item+1)%2) {
				continue;
			}
			flag = false;
			for(int j = i+1; j < board.size(); j++) {
				if(i%2 == j%2) {
					continue;
				}
				if(board[0][j] != board[0][i]) {
					for(int m = 0; m < board.size(); m++) {
						swap(board[m][i], board[m][j]);
					}
					res++;
					flag = true;
					break;
				}
			}
			if(!flag) {
				cout<<"false"<<endl;
				return -1;
			}
		}
		output(board);
        return res;
    }

    void output(vector<vector<int>>& board) {


		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board.size(); j++) {
				cout<< board[i][j] << " ";;
			}
			cout<<endl;
		}
		cout<<endl;
    }

};