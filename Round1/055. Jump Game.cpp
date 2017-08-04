class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int target = nums.size()-1, maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(maxLength < i) {
        		return false;
        	}

        	maxLength = max(maxLength, i + nums[i]);
        	if(maxLength >= target) {
        		return true;
        	}
        }
    	return false;
    }
};