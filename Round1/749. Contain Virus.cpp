class Solution {
public:
	class UF {
	public:

		UF(int m, int n) {
			M = m;
			N = n;
			count = 0;
			items.resize(M*N);
			fill(items.begin(), items.end(), -1);
			size.resize(M*N);
		}

		void unite(int x1, int y1, int x2, int y2) {
			// cout<<"unite: "<<x1<<"  " << y1<<" " << x2 << " " << y2<<endl;
			int root1 = findRoot(x1, y1);
			int root2 = findRoot(x2, y2);
			if(root1 != root2) {
				if(size[root1] < size[root2]){ //quick union
					items[root1] = root2;
					size[root2] += size[root1];
				} else {
					items[root2] = root1;
					size[root1] += size[root2];
				}
				count--;
			}
		}

		int findRoot(int x, int y) {
			int index = getIndex(x, y);
			if(index == -1 ) {
				return -1;
			}
			while(index != items[index]) {
				index = items[index];
				items[index] = items[items[index]]; //path comprass
			}
			return index;
		}

		void initItem(int x, int y) {
			int index = getIndex(x, y);
			if(items[index] >= 0) {
				return;
			}
			items[index] = index;
			size[index] = 1;
			count++;
		}

		bool isConnected(int x1, int y1, int x2, int y2) {
			return findRoot(x1, y1) == findRoot(x2, y2);
		}


		int getIndex(int x, int y) {
			return x*N + y;
		}

		int getCount() {
			return count;
		}
	private:
		vector<int> items;
		vector<int> size;
		int count;
		int M;
		int N;
	};

    int containVirus(vector<vector<int>>& grid) {
        int res = 0;
        UF uf(grid.size(), grid[0].size());
        set<int> seperated;
        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid[0].size(); j++) {
    			// uf.initItem(i, j);
    		}
    	}
        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid[0].size(); j++) {
        		if(grid[i][j] == 1) {
    				uf.initItem(i, j);
        			for(int x = i-1; x < (int)grid.size() && x <= i+1; x++) {
        				for(int y = j-1; y < (int)grid[0].size() && y <= j+1; y++) {
        					if(x < 0 || y < 0 || (x!= i && y != j)) {
        						continue;
        					}
        					if(grid[x][y] == 1) {
        						uf.unite(i, j, x, y);
        					}
        				}
        			}
        		}
        	}
        }
        printMatrix(grid);
        cout<<"UF:  " << uf.getCount()<<endl;
        int count = 0;
        while(true) {
       		map<int, int> walls;
       		int maxWalls = 0;
       		int maxIsland = -1;
       		bool find = false;
       		set<pair<int, int>> visited;
       		cout<<"start" << count<<endl;
	        for(int i = 0; i < grid.size(); i++) {
	        	for(int j = 0; j < grid[0].size(); j++) {
	        		if(grid[i][j] == 0) {
	        			continue;
	        		}
	        		int root = uf.findRoot(i, j);
	        		if(seperated.find(root) != seperated.end() ) {
	        			continue;
	        		}
	        		// cout<< "root. "<< i << "  " << j << "  " << root<<endl;
        			for(int x = i-1; x < (int)grid.size() && x <= i+1; x++) {
        				for(int y = j-1; y < (int)grid[0].size() && y <= j+1; y++) {
        					// cout<< x << "  " << y << "  " << i << "  "<< j<< endl;
        					if(x < 0 || y < 0 || grid[x][y] != 0 || (x != i && y != j)) {
        						// || visited.find(make_pair(x, y)) != visited.end()) {
        						continue;
        					}
        					visited.insert(make_pair(x, y));
        					// cout<<"try:  " <<  root << "  " << x << "  " << y << endl;
        					walls[root] ++;
        					if(walls[root] > maxWalls) {
	        					maxIsland = root;
	        					maxWalls = walls[root];
        					}
        				}
        			}
        		}
        	}
        	cout<<"Middle:  " << maxWalls <<". " << maxIsland << "  " << endl;
        	if(maxWalls != 0) {
	        	res += maxWalls;
	        	seperated.insert(maxIsland);
        	} else {
        		break;
        	}
        	set<pair<int, int>> injected;
	        for(int i = 0; i < grid.size(); i++) {
	        	for(int j = 0; j < grid[0].size(); j++) {
	        		if(grid[i][j] != 0 ) {
	        			continue;
	        		}
	        		bool flag = false;

        			for(int x = i-1; x < (int)grid.size() && x <= i+1; x++) {
        				for(int y = j-1; y < (int)grid[0].size() && y <= j+1; y++) {
        					if(x < 0 || y < 0 || (x != i && y != j)) {
        						continue;
        					}

        					if(grid[x][y] != 0) {
				        		int root = uf.findRoot(x, y);
				        		if(seperated.find(root) != seperated.end()) {
				        			continue;
				        		}
				        		flag = true;
    							uf.initItem(i, j);
	        					uf.unite(i, j, x, y);
        					} else {
	        					if(injected.find(make_pair(x, y)) != injected.end()) {
	        						uf.unite(i, j, x, y);
	        					}
        					}
        				}
        			}
        			if(flag) {
        				cout<<"injected: " << i << "  " << j << endl;
						injected.insert(make_pair(i, j));
        			}
	        	}
	        }
	        for(pair<int, int> p : injected) {
	        	grid[p.first][p.second] = count+2;
	        }
	        cout<<"Round" << count << "  " << uf.getCount() <<endl<<endl;
	        printMatrix(grid);
	        count++;
        }
        return res;
    }

    void printMatrix(vector<vector<int>>& grid) {
    	for(int i = 0; i < grid.size(); i++) {
    		for(int j = 0; j < grid.size(); j++) {
    			cout<<grid[i][j] << " ";
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    }
};