class Solution {
public:
	map<pair<int, int>, int> vRet;
	int ret;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	if(nums.size() == 0) {
    		return 0;
    	}
    	ret = 0;
    	helper(nums, 0, nums.size()-1, lower, upper);
        return vRet.size();
    }

    int helper(std::vector<int> & nums, int from, int to, int lower, int upper) {
    	int sum = 0;
    	if(vRet.find(pair<int, int>(from, to)) != vRet.end()) {
    		return vRet[pair<int, int>(from, to)];
    	}
    	if(to == from) {
    		sum = nums[from];
    	} else {
			for(int i = from+1; i < to; i++) {
	        	helper(nums, from, i, lower, upper);
	        }
	        sum = helper(nums, from, from, lower, upper) + helper(nums, from+1, to, lower, upper);
    	}
        if(sum <= upper && sum >= lower) {
        	// vRet[pair<int, int>(from, to)] = sum;
        	ret++;
        	cout<<from<<". " << to<<endl;
        }
        return sum;
    }
};