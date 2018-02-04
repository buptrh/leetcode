class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	if(nums.size() == 0) {
    		return 0;
    	}
    	int res = nums[0];
        int maxV = nums[0], minV = nums[0];
        for(int i = 1; i < nums.size(); i++) {
        	int nmaxV = max(nums[i], max(maxV*nums[i], minV*nums[i]));
        	int nminV = min(nums[i], min(maxV*nums[i], minV*nums[i]));
        	maxV = nmaxV;
        	minV = nminV;
        	res = max(res, maxV);

        }
        return res;
    }
};