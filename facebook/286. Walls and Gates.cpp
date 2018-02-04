class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    	if(rooms.size() == 0 || rooms[0].size() == 0) {
    		return;
    	}
        queue<pair<int, int>> que;
        for(int i = 0; i < rooms.size(); i++) {
        	for(int j = 0; j < rooms[0].size(); j++) {
        		if(rooms[i][j] == 0) {
        			que.push(make_pair(i, j));
        			rooms[i][j] = INT_MAX;
        		}
        	}
        }

        int round = 0;
        while(que.size() != 0) {
        	int size = que.size();
        	for(int i = 0; i < size; i++) {
        		int x = que.front().first;
        		int y = que.front().second;
        		if(x >= 0 && y >= 0 && x < rooms.size() && y < rooms[0].size() && rooms[x][y] > round) {
        			rooms[x][y] = round;
        			que.push(make_pair(x, y-1));
        			que.push(make_pair(x, y+1));
        			que.push(make_pair(x-1, y));
        			que.push(make_pair(x+1, y));
        		}
        		que.pop();
        	}
        	round++;
        }
    }
};