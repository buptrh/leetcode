class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1) {
    		return;
    	}
    	int index = -1;
        for(int i = nums.size()-1; i > 0; i--) {
        	if(nums[i] > nums[i-1]) {
        		index = i-1;
        		break;
        	}
        }
        if(index < 0) {
        	std::reverse(nums.begin(),nums.end());
        } else {
	        for(int i = nums.size()-1; i > index; i--){
	        	if(nums[i] > nums[index]) {
	        		swap(nums[i], nums[index]);
	        		break;
	        	}
	        }
	        std::reverse(nums.begin() + index + 1, nums.end());
        }
    }
};


//reverse and swap function