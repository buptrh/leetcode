class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	int left = 0, right = nums.size(), ret = 0;
    	sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == 0) {
        		continue;
        	}
    		left = i+1;
    		int rightMin = left, rightmax = nums.size()-1;
    		right = rightMin + 1;
    		while(left < rightmax) {
    			while(right <= rightmax && nums[right] - nums[left] < nums[i]) {
    				right++;
    			}
    			ret += right - left-1;
    			rightMin = right;
    			right = rightMin ;
    			left++;
    		}
        } 
        return ret;
    }
};