vector<int> partitionProblem(vector<int> & nums) {
	int sum = 0; 
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
    vector<vector<int>> path1(sum+1, vector<int>());
    vector<vector<int>> path2(sum+1, vector<int>());
    for (int i = 0; i <= nums.size(); i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(dp[i][j]) {
            	path1[j] = path2[j];
            } else if(j-nums[i-1] >= 0 && dp[i-1][j-nums[i-1]]) {
                dp[i][j] = dp[i-1][j-nums[i-1]];
                path1[j] = path2[j-nums[i-1]];
            	path1[j].emplace_back(nums[i-1]);
            }
        }
        path2 = path1;
        path1 = vector<vector<int>>(sum+1, vector<int>());
    }
    vector<int> ret;
    for (int j = sum/2; j >= 0; j--) {
        if (dp[nums.size()][j] == true) {
            ret = path2[j];
            break;
        }
    }
    return ret;
}


