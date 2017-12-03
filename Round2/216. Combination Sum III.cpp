class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
    	vector<int> path;
        helper(ret, path, k, n, 1);
        return ret;
    }
    void helper(vector<vector<int>> & ret, vector<int> & path, int k, int n, int pos) {
        if(k < 0 || (k == 0 && n != 0)) {
            return;
        } else if(n == 0 && k == 0) {
            ret.emplace_back(path);
            return;
        } else if(n >= pos) {
            
        } else {
            return;
        }
        for(int i = pos; i <= 9; i++) {
            path.push_back(i);
            helper(ret, path, k-1, n-i, i+1);
            path.pop_back();
        }
    }

};