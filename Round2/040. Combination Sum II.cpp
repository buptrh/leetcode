class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, path, target, ret);
        return ret;
    }

    void helper(vector<int> & candidates, int pos, vector<int> & path, int target, vector<vector<int>> & ret) {
        if(target < 0) {
            return;
        } else if(target == 0) {
            ret.emplace_back(path);
            return;
        }

        for(int i = pos; i < candidates.size(); i++) {
            if(i != pos && candidates[i] == candidates[i-1]) {
                continue;
            }
            path.emplace_back(candidates[i]);
            helper(candidates, i+1, path, target - candidates[i], ret);
            path.pop_back();
        }
    }
};