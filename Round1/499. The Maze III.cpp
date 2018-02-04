class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int row = maze.size();
		if(row == 0) {
			return "";
		}
		int col = maze[0].size();
		if(col == 0) {
			return "";
		}

		map<pair<int, int>, string> paths;
		vector<int> dx{-1, 0, 1, 0};
		vector<int> dy{0, -1, 0, 1};
		vector<string> direStr{"u", "l", "d", "r"};//“down”, “left”, “up”, “right”);
		pair<int, int> dest = make_pair(hole[0], hole[1]);

		queue< pair<int, int>> que;
		que.push(make_pair(ball[0], ball[1]));
		while(!que.empty()) {
			int size = que.size();
			for(int i = 0; i < size; i++) {
				pair<int, int> & pos = que.front();
				que.pop();
				if(pos == dest) {
					// cout<<"!!!~~~" << paths[dest]<<endl;
					return paths[dest];
				}
				for(int j = 0; j < 4; j++) {
					int x = pos.first;
					int y = pos.second;
					if(dx[j] != 0) {
						while(x + dx[j] < row && x + dx[j] >= 0 && maze[x+dx[j]][y] != 1){
							x += dx[j];
							// cout<<direStr[j]<<endl;
							if(make_pair(x, y) == dest) {
								// cout<<"!!!" << direStr[j]<<endl;
								return paths[pos] + direStr[j];
							}
						}
					} else {
						while(y + dy[j] < row && y + dy[j] >= 0 && maze[x][y+dy[j]] != 1){
							y += dy[j];
							// cout<<direStr[j]<<endl;
							if(make_pair(x, y) == dest) {
								// cout<<"~~~" << direStr[j]<<endl;
								return paths[pos] + direStr[j];
							}
						}
					}
					pair<int, int> newpos = make_pair(x, y);
					if((x != pos.first || y != pos.second) &&paths.find(newpos) == paths.end()) {
						que.push(newpos);
						paths[newpos] = paths[pos]+direStr[j];
						// cout<<"final: " << newpos.first<< "  " << newpos.second << "  " << paths[newpos]<<endl;
					}
				}
			}
		}
		return "";
    }
};
