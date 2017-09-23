class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        for(int i = 0; i < nums.size()-1; i++) {
        	ret[i+1] = nums[i] * ret[i];
        }
        int val = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
        	ret[i] *= val;
        	val *= nums[i];
        }
        return ret;
    }
};