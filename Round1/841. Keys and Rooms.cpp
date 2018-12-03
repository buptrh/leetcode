class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	if(rooms.size() == 0) {
    		return true;
    	}
        int count = rooms.size();
        vector<bool> opens (count, false);
        bfs(rooms, opens, 0);
    	for(int j = 0; j < rooms.size(); j++) {
    		if(!opens[j]) {
    			return false;
    		}
    	}
        return true;
    }

    void bfs(vector<vector<int>>& rooms, vector<bool> & opens, int i) {
    	if(opens[i]) {
    		return;
    	}
    	opens[i] = true;
    	for(int j = 0; j < rooms[i].size(); j++) {
    		bfs(rooms, opens, rooms[i][j]);
    	}
    }
};