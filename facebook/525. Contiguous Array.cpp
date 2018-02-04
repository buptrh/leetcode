class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> table;
        table[0] = -1;
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == 0) {
        		sum --;
        	} else {
        		sum ++;
        	}
        	if(table.find(sum) != table.end()) {
        		res = max(res, i - table[sum]);
        	} else {
        		table[sum] = i;
        	}
        }
        return res;
    }
};