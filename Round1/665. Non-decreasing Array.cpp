class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    	int count = 0;
    	if(nums.size() == 0) {
    		return true;
    	}
        for(int i = 0; i < nums.size()-1; i++) {
        	if(nums[i] > nums[i+1]) {
        		count++;
        		if(count > 1) {
        			return false;
        		}
        		if(i > 0 && nums[i+1] < nums[i-1] && i+2 < nums.size() && nums[i] > nums[i+2]) {
        			return false;
        		}
        	}
        }
        return true;
    }
};