
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    	if(nums.size() == 0) {
    		return -1;
    	}
    	int sum = 0, cur = 0;
    	for(int i = 0; i < nums.size(); i++) {
    		sum += nums[i];
    	}
        
        for(int i = 0; i < nums.size(); i++) {
        	if(2*cur  + nums[i] == sum) {
        		return i;
        	}
        	cur += nums[i];
        }
        return -1;
    }
};