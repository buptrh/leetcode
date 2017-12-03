class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> table;
        int count = 0;
        for(int i : nums) {
        	if(table[i] == 0) {
        		count++;
        	}
        	table[i] ++;
        }
        //dp[i] = dp[i+1] + dp[i-1];

        vector<int> dp(count+2);
        int index = 2, prev = -1;

        for(auto it : table) {
        	int val = it.first * it.second;
    		dp[index] = max(dp[index-2] + val, dp[index-1]);
    		if(prev != it.first-1) {
    			dp[index] = max(dp[index], dp[index-1] + val);
    		}
    		prev = it.first;
        	index++;
        }
        return dp[count+1];
    }
};