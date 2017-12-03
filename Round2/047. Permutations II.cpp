class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> dup;
        // sort(nums.begin(), nums.end());
        helper(nums, dup, ret);
    	return ret;
    }

    void helper(vector<int>& nums, vector<int> & dup, vector<vector<int>> & ret) {
        if(dup.size() == nums.size()) {
            vector<int> vec;
            for(int i = 0; i < dup.size(); i++) {
                vec.emplace_back(nums[dup[i]]);
            }
            ret.emplace_back(vec);
            return;
        }
        set<int> se;
        for(int i = 0; i < nums.size(); i++) {
            if( find (dup.begin(), dup.end(), i) != dup.end()) {
                continue;
            }
            if(se.find(nums[i]) != se.end()) {
                continue;
            }
            se.insert(nums[i]);
            dup.push_back(i);
            helper(nums, dup, ret);
            dup.pop_back();
        }
    }

};