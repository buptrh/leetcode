class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    	if(nums.size() < 2) {
    		return -1;
    	}
        bool flag = false;
        int max1 = -1, max2 = -1;
        for(int i = 0; i < nums.size(); i++) {
        	if(max1 < 0 || nums[i] > nums[max1]) {
        		max2 = max1;
        		max1 = i;
        	} else if(max2 < 0 || nums[i] > nums[max2]) {
        		max2 = i;
        	}
    		if(max1 >= 0 && max2 >= 0 && nums[max1] >= nums[max2] * 2) {
    			flag = true;
    		} else {
    			flag = false;
    		}
        }
        cout<<max1 << "  " << max2 <<endl;
        if(flag) {
        	return max1;
        } else {
        	return -1;
        }
    }
};