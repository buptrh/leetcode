class Solution {
public:
        unordered_set<string> visited;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, vector<char>> table;
        for(string s : allowed) {
        	table[s.substr(0, 2)].push_back(s[2]);
        }
        return helper(bottom, table);

    }

    bool helper(string bottom, map<string, vector<char>>& table) {
    	if(visited.find(bottom) != visited.end()) {
    		return true;
    	}
    	if(bottom.size() <= 1) {
    		return true;
    	}
    			// cout<< "helper: " << bottom << endl;
    	string test;
    	vector<vector<char>> replace;
    	for(int i = 0; i < bottom.size()-1; i++) {
    		string s = bottom.substr(i, 2);
    		vector<char> vec = table[s];
    		if(vec.size() == 0) {
    		// cout<< "fail. " << s << endl;
    			return false;
    		}
			test.push_back(vec[0]);
			replace.push_back(vec);
    	}
    	// cout << "next " << test << endl;
    	if(helper2(test, 0, replace, table)) {
    		visited.insert(test);
    		return true;
    	}
    	return false;
    }

    bool helper2(string bottom, int start, vector<vector<char>> & replace, map<string, vector<char>>& table) {
    	if(visited.find(bottom) != visited.end()) {
    		return true;
    	}
    	if(start >= bottom.size() ) {
    		return false;
    	}
		// cout<< "helper2: " << bottom << endl;
    	for(int i = 0; i < replace[start].size(); i++) {
    		bottom[start] = replace[start][i];
    		if(helper(bottom, table)) {
    			visited.insert(bottom);
    			return true;
    		}
    		if(helper2(bottom, start+1, replace, table)) {
    			visited.insert(bottom);
    			return true;
    		}
    		bottom[start] = replace[start][0];
    	}
    	return false;
    }
};