class NumArray {
public:
	std::vector<int> sums;
    NumArray(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) {
        	if(i > 0) {
        		sums.emplace_back(sums[i-1] + nums[i]);
        	} else {
        		sums.emplace_back(nums[i]);
        	}
        	// cout<<sums[i]<<endl;
        }
    }
    
    int sumRange(int i, int j) {
    	int ret = sums[j];
    	if(i > 0) {
    		ret -= sums[i-1];
    	}
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */