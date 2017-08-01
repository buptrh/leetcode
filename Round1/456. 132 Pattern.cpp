class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	if(nums.size() < 3) {
    		return false;
    	}

    	vector<vector<int> > table;
    	int index = -1;
    	for(int i = nums.size()-1; i >= 0 ; i--) {
    		if(nums[i] > max1) {
    			max1 = nums[i];
    		} else if(nums[i] > max2) {
    			max2 = nums[i];
    		}
    	}
    }
};