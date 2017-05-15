class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == val) {
        		length++;
        	} else {
        		if(i - length >= 0) {
        			nums[i-length] = nums[i];
        		}
        	}
        }
        return nums.size() - length;
     }
};


//better answer: if length is the items != val, we don't need nums[i] == val;