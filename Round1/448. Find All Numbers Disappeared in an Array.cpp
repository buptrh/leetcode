class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> ret;
    	if(nums.size() == 0) {
    		return ret;
    	}
    	if(nums.size() == 1) {
    		if(nums[0] == 1) {
    			return ret;
    		} else {
    			ret.emplace_back(1);
    			return ret;
    		}
    	}
    	int m = 0;
        for(int i = 0; i < nums.size(); i ++) {
        	if(nums[i] == 0) {
        		continue;
        	}
        	m = nums[i];
        	while(nums[m-1] != 0) {
                // cout<<nums[m-1] <<endl;
                int temp = nums[m-1];
                nums[m-1] = 0;
                m = temp;
        	}
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                ret.emplace_back(i+1);
            }
        }

        return ret;
    }
};