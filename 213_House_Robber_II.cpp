class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size() == 0) {
    		return 0;
    	}
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if( i % 2 == 0) {
        		if(i != nums.size()-1 || i == 0) {
        			a1 = max(a1 + nums[i], b1);
        		}
        		if(i != 0) {
        			a2 = max(a2 + nums[i], b2);
        		}
        	} else {
        		if(i != nums.size()-1 || i == 0) {
        			b1 = max(b1 + nums[i], a1);
        		}
        		if(i != 0) {
        			b2 = max(b2 + nums[i], a2);
        		}
        	}
        }
        return max( max(a1, b1), max(a2, b2));
    }
};