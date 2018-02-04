class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        int sum = 0, res = 0;
        table[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
        	sum += nums[i];
        	if(table.find(sum) == table.end()) {
        		table[sum] = i+1;
        	}
        	if(table.find(sum - k) != table.end()) {
        		res = max(res, i - table[sum-k] + 1);
        	}
        }
        return res;
    }
};