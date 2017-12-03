class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        helper(n, ret, 1, path, k);
        return ret;
    }

    void helper(int n, vector<vector<int>> & ret, int pos, vector<int> & path, int k) {
    	for(int i = pos; i <= n; i++) {
    		path.emplace_back(i);

	    	if(path.size() == k) {
	    		ret.emplace_back(path);
	    	} else{
    			helper(n, ret, i+1, path, k);
	    	}
    		path.pop_back();
    	}
    }
};