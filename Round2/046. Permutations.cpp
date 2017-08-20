class Solution {
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
};