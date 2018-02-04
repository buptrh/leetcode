class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < (int)nums.size()-2; i++) {
        	int t = target - nums[i];
        	int l = i+1, r = nums.size()-1;
        	while(l < r) {
        		if(nums[l] + nums[r] < t) {
        			res += r - l;
        			l++;
        		} else {
        			r--;
        		}
        	}
        }
        return res;
    }
};