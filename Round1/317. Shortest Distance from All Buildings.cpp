class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
    	int row = grid.size();
    	if(row == 0) {
    		return 0;
    	}
    	int col = grid[0].size();
    	if(col == 0) {
    		return 0;
    	}
        queue<pair<int, int>> buildings;
        vector<set<pair<int, int>>> vec; 
        for(int i = 0; i < row; i++) {
        	for(int j = 0; j < col; j++) {
        		if(grid[i][j] == 1) {
        			buildings.push(make_pair(i, j));
        			vec.push_back(set<pair<int, int>>());
        		}
        	}
        }
        map<pair<int, int>, int> sums;
        int res = INT_MAX;
        while(buildings.size() > 0) {
        	pair<int, int> building = buildings.front();
        	buildings.pop();

       		map<pair<int, int>, int> dist;
        	queue<pair<int, int>> coords;
        	set<pair<int, int>> dup;

        	coords.push(building);
        	int count = 0;

        	while(!coords.empty()) {
        		int size = coords.size();
        		for(int i = 0; i < size; i++) {
        			pair<int, int> coord = coords.front();
        			coords.pop();
        			if(coord.first < 0 || coord.first >= row || coord.second < 0 || coord.second >= col ) {
        				continue;
        			}
        			if((coord != building && grid[coord.first][coord.second] != 0) || dup.find(coord) != dup.end()) {
        				continue;
        			}
        			dup.insert(coord);
        			dist[coord] = count;
        			coords.push(make_pair(coord.first+1, coord.second));
        			coords.push(make_pair(coord.first-1, coord.second));
        			coords.push(make_pair(coord.first, coord.second+1));
        			coords.push(make_pair(coord.first, coord.second-1));
        		}
        		count++;
        	}

        	for(int i = 0; i < row; i++) {
        		for(int j = 0; j < col; j++) {
        			pair<int, int> p =make_pair(i, j);
        			if(grid[i][j] == 0 && sums[p] != INT_MAX){
        				if(dist[p] == 0) {
        					sums[p] = INT_MAX;
        					continue;
        				}
	        			sums[p] += dist[p];
			        	if(buildings.size() == 0) {
			        		res = min(res, sums[p]);
			        	}
        			}
        		}
        	}
        }
        if(res == INT_MAX || res <= 0) {
        	res = -1;
        }
        return res;
    }
};