class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
    	vector<vector<int>> pers = permute(nums);
    	for(int i = 0; i < pers.size(); i++) {
    		if( helper(pers[i], 1, pers[i][0]) ) {
    			return true;
    		}
    	}
    	return false;
    }

    bool helper(vector<int> & nums, int start, double val) {
    	
    	if(start > 3) {
    		if(val == 24) {
    			return true;
    		}
    		return false;
    	}
    	if(start == 2) {
    		if(val * (nums[2]+nums[3]) == 24 || val * (nums[2]-nums[3]) == 24 || val * (nums[3]-nums[2]) == 24 ) {
    			return true;
    		}
    		if(((nums[2]+nums[3]) != 0 && val / (nums[2]+nums[3]) == 24) || ( (nums[2]-nums[3]) != 0 && val / (nums[2]-nums[3]) == 24) || ( (nums[3]-nums[2]) != 0 && val / (nums[3]-nums[2]) == 24 )) {
    			return true;
    		}
    	}

    	if(helper(nums, start+1, (double)nums[start]+val) 
    		|| helper(nums, start+1, val - (double)nums[start]) 
    		|| helper(nums, start+1, (double)nums[start] - val) 
    		|| helper(nums, start+1, (double)nums[start] * val)
    		|| (nums[start] != 0 && helper(nums, start+1, (double)val / (double)nums[start])) 
    		|| (val != 0 && helper(nums, start+1, (double)nums[start] / (double)val ))) {
    		return true;
    	}
        
        return false;
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> dup;
        solve(nums, dup, ret);
        return ret;
    }

    void solve(vector<int> & nums, vector<int> & dup, vector<vector<int>> & ret) {
        if(dup.size() == nums.size()) {
        	vector<int> ins;
        	for(int i = 0; i < dup.size(); i++) {
        		ins.emplace_back(nums[dup[i]]);
        	}
            ret.emplace_back(ins);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if( find (dup.begin(), dup.end(), i) != dup.end()) {
                continue;
            }
            dup.push_back(i);
            solve(nums, dup, ret);
            dup.pop_back();
        }
    }
};