class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
    	int ret = 0, row = forest.size();
    	if (row == 0) {
    		return 0;
    	}
    	int col = forest[0].size();
    	vector<pair<int, int>> forest2;
    	for(int i = 0; i < row; i++) {
    		for(int j = 0; j < col; j++) {
    			forest2.emplace_back(pair<int, int>(i, j));
    		}
    	}
		auto comp = [&forest](pair<int, int> a, pair<int, int> b) {
		    return forest[a.first][a.second] < forest[b.first][b.second];
		};
		sort(forest2.begin(), forest2.end(), comp);
		int current = 0;
		for(int i = 0; i < forest2.size(); i++) {
			if(forest[forest2[i].first][forest2[i].second] > 1) {
				current = i;
				break;
			}
		}
		vector<vector<int>> dp(row, vector<int>(col, 0));

		int i = 0, j = 0;
		queue<pair<int, int>> que;
		while(current < forest2.size()) {
			int w = getDist(forest, i, j, forest2[current].first, forest2[current].second);
			// cout<<forest[forest2[current].first][forest2[current].second]<<".  " << w << endl;
			if(w < 0) {
				return -1;
			}
			i = forest2[current].first;
			j = forest2[current].second;
			current++;
			ret += w;
			forest[forest2[current].first][forest2[current].second] = 1;
			if(current == forest2.size()) {
				return ret;
			}
		}
		return ret; 
    }

    int getDist(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
    	return abs(sr-er) + abs(sc-ec);
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        if (forest[sr][sc] == 0) {
            return -1;
        }
        unordered_set<int> visited;
        q.push(make_pair(sr, sc));
        visited.insert((sr << 16) | sc);
        for (int d = 0; !q.empty(); d++) {
            int size = q.size();
            for (int t = 0; t < size; ++t) {
                pair<int, int> cur = q.front(); q.pop();
                // printf("d = %d, cur = %d, %d\n", d, cur.first, cur.second);
                if (cur.first == er && cur.second == ec) {
                    return d;
                }
                for (int i = 0; i < 4; ++i) {
                    int nr = cur.first + dr[i];
                    int nc = cur.second + dc[i];
                    //printf("nr = %d, nc = %d\n", nr, nc);
                    if (nr < 0 || nr >= forest.size() || nc < 0 || nc >= forest[0].size() || forest[nr][nc] == 0) {
                        continue;
                    }
                    int key = (nr << 16) | nc;
                    if (visited.find(key) != visited.end()) {
                        continue;
                    }
                    visited.insert(key);
                    q.push(make_pair(nr, nc));
                }
            }
        }
        return -1;
    }
};












