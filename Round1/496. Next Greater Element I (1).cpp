class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> ret;
    	for(int j = 0; j < findNums.size(); j++) {
    		bool flag = false;
	    	for(int i = 0; i < nums.size(); i++) {
	    		if(flag) {
	    			if(nums[i] > findNums[j]) {
	    				ret.emplace_back(nums[i]);
	    				break;
	    			}
	    		} else {
		    		if(nums[i] == findNums[j]) {
		    			flag = true;
		    		}
	    		}
	    	}

	    	if(ret.size() < j+1) {
	    		ret.emplace_back(-1);
	    	}
    	}
    	return ret;
    }
};