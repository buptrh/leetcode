class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    	vector<int> res;
    	for(int i = 0; i < hits.size(); i++) {
    		res.push_back(0);
    	}
    	if(grid.size() == 0 || grid[0].size() == 0 || res.size() == 0) {
    		return res;
    	}
        map<pair<int, int>, set<pair<int, int>>> relyon;
        map<pair<int, int>, set<pair<int, int>>> relyby;
        set<pair<int, int>> blocks;
        for(int i = 0; i < grid.size(); i++) {
        	for(int j = 0; j < grid[0].size(); j++) {
        		if(i == 0) {
        			blocks.insert(make_pair(i, j));
        			dfs(i, j, grid, make_pair(-1, -1), relyon, relyby, blocks);
        		}
        	}
        }
        cout<< "!!!" << endl;
        for(int i = 0; i < hits.size(); i++) {
        	cout<<i<<endl;
        	pair<int, int> current = make_pair(hits[i][0], hits[i][1]);
        	if(blocks.count(current) == 0) {
        		continue;
        	}
        	set<pair<int, int>> tocheck = relyby[current];
        	cout<< i << "  " << tocheck.size() << endl;
        	for(auto ch : tocheck) {
        		relyon[ch].erase(current);
        		if(relyon.size() == 0) {
        			blocks.erase(ch);
        			res[i]++;
        		}
        	}
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, pair<int, int> from,
    	map<pair<int, int>, set<pair<int, int>>> & relyon, 
    	map<pair<int, int>, set<pair<int, int>>>& relyby,
    	set<pair<int, int>>& blocks) 
    {
    	// cout<<"dfs: " << i << j << endl;
    	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
    		return;
    	}
    	pair<int, int> current = make_pair(i, j);
    	if(relyon[current].count(from) > 0) {
    		return;
    	}
    	if(blocks.count(current) == 0) {
    		blocks.insert(current);
    	}
    	relyon[current].insert(from);
    	relyby[from].insert(current);
    	dfs(i+1, j, grid, make_pair(i, j), relyon, relyby, blocks);
    	dfs(i-1, j, grid, make_pair(i, j), relyon, relyby, blocks);
    	dfs(i, j+1, grid, make_pair(i, j), relyon, relyby, blocks);
    	dfs(i, j-1, grid, make_pair(i, j), relyon, relyby, blocks);
    }
};