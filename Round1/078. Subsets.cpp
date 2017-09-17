class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        helper(nums, path, ret, 0);
        return ret;
    }

    void helper(vector<int> & nums, vector<int> & path, vector<vector<int>> & ret,  int pos) {
    	ret.emplace_back(path);
    	for(int i = pos; i < nums.size(); i++) {
    		path.emplace_back(nums[i]);
    		helper(nums, path, ret, i+1);
    		path.pop_back();
    	}
    }
};