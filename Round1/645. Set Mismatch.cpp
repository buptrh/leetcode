class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<int> ret;
        int val = 1;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size()-1; i++) {
        	if(nums[i] == nums[i+1]) {
        		ret.emplace_back(nums[i]);
        	}
            sum += nums[i];
        }
        sum += nums[n-1];
        int sum2 = (n*(n+1)) / 2;
        ret.emplace_back(ret[0] + sum2-sum);
    	return ret;
    }
};