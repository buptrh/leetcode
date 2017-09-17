class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.size() <= 1) {
    		return 0;
    	}
    	int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
        	if(nums[i] < nums[i-1]) {
        		minVal = min(minVal, nums[i]);
        		maxVal = max(maxVal, nums[i-1]);
        	} 
        }
        // cout<<minVal << " " << maxVal <<endl;
        int start = -1, end = -1;
        for(int i = 0; i < nums.size(); i++ ) {
        	if(nums[i] > minVal) {
        		start = i;
        		break;
        	}
        }
        for(int i = nums.size()-1; i >= 0; i-- ) {
        	if(nums[i] < maxVal) {
        		end = i;
        		break;
        	}
        }
        if(start == -1 && end == -1) {
        	return 0;
        } 
        // cout<<start << " " << end <<endl;
        return end - start + 1;
    }
};