class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> path;
        helper(ret, path, n);
        return ret;
    }

    void helper(vector<vector<string>> & ret, vector<int> & path, int n) {
    	if(path.size() == n) {
    		vector<string> vec;
    		for(int i = 0; i < n; i ++) {
				string s;
				for(int j = 0; j < n; j++) {
					if(j != path[i]) {
						s += '.';
					} else {
						s += 'Q';
					}
				}
				vec.emplace_back(s);
    		}
    		ret.emplace_back(vec);
    		return;
    	}
    	for(int i = 0; i < n; i++) {
    		bool flag = true;
    		for(int j = 0; j < path.size(); j++) {
    			if(i == path[j] || (abs(i - path[j]) == abs(path.size() - j)) ) {
    				flag = false;
    				break;
    			}
    		}
    		if(!flag) {
    			continue;
    		}
    		path.emplace_back(i);
    		helper(ret, path, n);
    		path.pop_back();
    	}
    }
};