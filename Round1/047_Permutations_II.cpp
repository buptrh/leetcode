class Solution {
public:
	vector<vector<int>> ret;
	int count;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	std::vector<int> results;
    	count = nums.size();
		std::vector<bool> visited(nums.size(), false);
    	solve(nums, results, visited);
    	return ret;
    }

    void solve(vector<int>& nums, vector<int> results, vector<bool> visited) {

		set<int> duplicates;
    	for(int i = 0; i < nums.size(); i ++) {
    		if(visited[i] || duplicates.find(nums[i]) != duplicates.end()) {
    			continue;
    		}
    		visited[i] = true;
    		duplicates.insert(nums[i]);
    		results.push_back(nums[i]);
    		count--;
    		if(count == 0) {
    			ret.emplace_back(results);
    		} else {
    			solve(nums, results, visited);
    		}
    		count++;
    		results.pop_back();
    		visited[i] = false;
    	}
    }
};