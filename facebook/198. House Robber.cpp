class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        vector<int> dpPath(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            dpPath[i] = i;
            if(i >= 2) {
                if(dp[i-2] + nums[i] > dp[i]) {
                    dpPath[i] = i-2;
                    dp[i] = dp[i-2] + nums[i];
                }
            }
            if(i >= 1) {
                if(dp[i-1] > dp[i]) {
                    dpPath[i] = i-1;
                    dp[i] = dp[i-1];
                }
            }
        }
        vector<int> paths;
        int current = nums.size()-1;
        while(current != dpPath[current]) {
            if(dpPath[current] < current-1) {
                paths.push_back(current);
            }
            current = dpPath[current];
        }
        paths.push_back(current);
        reverse(paths.begin(), paths.end());
        for(int i : paths) {
            cout<<i << " ";
        }
        cout<<endl;
        return dp[nums.size()-1];
    }
};