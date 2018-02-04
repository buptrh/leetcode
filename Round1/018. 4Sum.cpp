class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        findNSum(nums, 4, target, 0, path, res);
        return res;
    }

    void findNSum(vector<int> & nums, int N, int target, int start, vector<int> & path, vector<vector<int>> & res) {
    	// cout<< N << "  " << start<<". " << target<<endl;
    	if(N == 2) {
    		int lo = start, hi = nums.size()-1;
    		while(lo < hi) {
    			if(nums[lo] + nums[hi] == target) {
    				path.push_back(nums[lo]);
    				path.push_back(nums[hi]);
    				res.push_back(path);
    				while(lo < hi && nums[lo] == nums[lo+1]) {
    					lo++;
    				}
    				while(lo < hi && nums[hi] == nums[hi-1]) {
    					hi--;
    				}
    				lo++;
    				hi--;
    				path.pop_back();
    				path.pop_back();
    			} else if(nums[lo] + nums[hi] < target) {
    				lo++;
    			} else {
    				hi--;
    			}
    		}
    	} else {
    		for(int i = start; i < nums.size(); i++) {
    			if(i > start && nums[i] == nums[i-1]) {
    				continue;
    			}
    			path.push_back(nums[i]);
    			findNSum(nums, N-1, target - nums[i], i+1, path, res);
    			path.pop_back();
    		}
    	}
    }
};