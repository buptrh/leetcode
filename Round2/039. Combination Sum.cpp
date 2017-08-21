class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        helper(candidates, target, ret, path, 0);
        return ret;
    }

    void helper(vector<int>& candidates, int target, vector<vector<int>> & ret, vector<int> & path, int pos) {
        if(target < 0) {
            return;
        } else if(target == 0) {
            ret.emplace_back(path);
            return;
        }
        for(int i = pos; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            helper(candidates, target - candidates[i], ret, path, i);
            path.pop_back();
        }
    }

};