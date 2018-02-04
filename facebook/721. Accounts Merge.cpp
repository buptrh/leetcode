class Solution {
public:
	class UF {
	public:
		UF() {

		}

		void init(string e) {
			if(unions.find(e) == unions.end()) {
				unions[e] = e;
			}
		}
		void unite(string e1, string e2) {
			unions[findRoot(e2)] = findRoot(e1);
		}

		string findRoot(string s) {
			// cout<<" !!find root: " << s << endl;
			while(unions[s] != s) {
				s = unions[s];
				unions[s] = unions[unions[s]];
			}
			return s;
		}

		bool isConnected(string e1, string e2) {
			if(findRoot(e1) == findRoot(e2)) {
				return true;
			}
			return false;
		}
		unordered_map<string, string>& getUnions() {
			return unions;
		}


	private:
        unordered_map<string, string> unions;

	};
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	UF uf;
    	unordered_map<string, string> names;
        for(int i = 0; i < accounts.size(); i++) {
        	for(int j = 1; j < accounts[i].size(); j++) {
        		names[accounts[i][j]] = accounts[i][0];
        		uf.init(accounts[i][j]);
        		if(j > 1) {
        			uf.unite(accounts[i][j], accounts[i][j-1]);
        		}
        	}
        }
		unordered_map<string, string> & unions = uf.getUnions();
		vector<vector<string>> res;
		unordered_map<string, set<string>> emails;
        // cout<<"test 1" << endl;
		for(auto u : unions) {
			// cout<<"  try: " << u.first << "  " << u.second << endl;
			// cout<< "  root: " << uf.findRoot(u.first) << endl;
			emails[uf.findRoot(u.first)].insert(u.first);
			// cout<<"  finish try \n";
		}

        // cout<<"test 2" << endl;
		for(auto u : emails) {
			vector<string> r;
			r.push_back(names[u.first]);
			for(auto s : u.second) {
				r.push_back(s);
			}
			res.push_back(r);
		}
        // cout<<"test 3" << endl;
		return res;
    }
};



/*class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	map<string, vector<int>> table;
    	for(int i = 0; i < accounts.size(); i++) {
    		for(int j = 1; j < accounts[i].size(); j++) {
    			table[accounts[i][j]].push_back(i);
    		}
    	}
    	vector<vector<string>> res;
    	set<string> visited;
    	for(auto email : table) {
    		if(visited.find(email.first) != visited.end()) {
    			continue;
    		}
    		set<string> path;
    		for(int i = 0; i < email.second.size(); i++) {
    			dfs(accounts, email.second[i], table, path, visited);
    		}
    		vector<string> r;
    		r.push_back(accounts[email.second[0]][0]);
    		for(auto email : path) {
    			r.push_back(email);
    		}
    		res.push_back(r);
    	}

    	return res;
    }

    void dfs(vector<vector<string>>& accounts, int index, map<string, vector<int>>& table, set<string>& path, set<string>& visited) {
    	vector<string> & emails = accounts[index];
    	for(int i = 1; i < emails.size(); i++) {
    		if(visited.find(emails[i]) != visited.end()) {
    			continue;
    		}
    		path.insert(emails[i]);
    		visited.insert(emails[i]);
    		for(int j = 0; j < table[emails[i]].size(); j++) {
    			dfs(accounts, table[emails[i]][j], table, path, visited);
    		}
    	}
    }
};*/