class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	if(nums.size() == 0) {
    		return 0;
    	}
        unordered_map<int, int> table;
		table[nums[0]] += 1;
		table[-nums[0]] += 1;
        for(int i = 1; i < nums.size(); i++) {
        	unordered_map<int, int> table2;
        	for(auto k : table) {
        		table2[k.first+nums[i]] += k.second;
        		table2[k.first-nums[i]] += k.second;
        	}
        	table = table2;
        }
        return table[S];
    }
};