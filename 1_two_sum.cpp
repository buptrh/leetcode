class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> ret(2);
        for(size_t i = 0; i < nums.size() - 1; i ++) {
        	for(size_t j = i+1; j < nums.size(); j++) {
        		if(nums[i] + nums[j] == target) {
        			ret[0] = i;
        			ret[1] = j;
        			return ret; 
        		}
        	}
        }
    }
};