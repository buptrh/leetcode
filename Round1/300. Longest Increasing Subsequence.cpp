class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int ret = 0;
    	vector<int> arr(nums.size(), 1);
        for(int i = nums.size()-1; i >= 0; i--) {
        	int val = 1;
        	for(int j = i+1; j < nums.size(); j++) {
        		if(nums[i] < nums[j]) {
        			val = max(val, arr[j]+1);
        		}
        	}
        	arr[i] = val;
        	// cout<<i << "  " << val << endl;
        	ret = max(ret, val);
        }
        return ret;
    }
};