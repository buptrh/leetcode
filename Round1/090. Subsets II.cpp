class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = helper(nums, 0);
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }

    vector<vector<int>> helper(vector<int>& nums, int index) {
    	vector<vector<int>> ret;
    	if(index == nums.size()-1) {
    		ret.emplace_back(vector<int>());
    		vector<int> r1;
    		r1.emplace_back(nums[index]);
    		ret.emplace_back(r1);
    		return ret;
    	}
    	vector<vector<int>> r = helper(nums, index+1);
    	for(int i = 0; i < r.size(); i++) {
    		vector<int> r1 = r[i];
    		ret.emplace_back(r1);
    		r1.emplace_back(nums[index]);
    		ret.emplace_back(r1);
    	}
    	// cout<<ret.size() << endl;
    	return ret;
    }
};