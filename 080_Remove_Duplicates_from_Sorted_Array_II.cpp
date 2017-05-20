class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() <= 1) {
    		return nums.size();
    	}
    	int i = 0;
        while(i < nums.size() - 2) {
        	if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) {
        		nums.erase(nums.begin() + i);
        	} else {
        		i++;
        	}
        }
        return nums.size();
    }
};


//no need to compare nums[i] and nums[i+1]
//it has better performance if don't erase. just copy.