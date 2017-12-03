/*class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        solve(nums, 0, ret);
        return ret;
    }

    void solve(vector<int> & nums, int pos, vector<vector<int>> & ret) {
        if(pos >= nums.size()) {
            ret.emplace_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            solve(nums, pos+1, ret);
            swap(nums[i], nums[pos]);
        }
    }
};*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> dup;
        helper(nums, dup, ret);
        return ret;
    }

    void helper(vector<int> & nums, vector<int> & dup, vector<vector<int>> & ret) {
        if(dup.size() == nums.size()) {
            ret.emplace_back(dup);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if( find (dup.begin(), dup.end(), nums[i]) != dup.end()) {
                continue;
            }
            dup.push_back(nums[i]);
            helper(nums, dup, ret);
            dup.pop_back();
        }
    }
};