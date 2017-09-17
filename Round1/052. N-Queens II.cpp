class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> path;
        helper(ret, path, n);
        return ret;
    }

    void helper(int & ret, vector<int> & path, int n) {
    	if(path.size() == n) {
    		ret++;
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