class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0, ca = 0, cb = 0;
        for(int i = 0; i < nums.size(); i ++) {
        	if(a == nums[i]) {
        		ca++;
        	} else if (b == nums[i] ) {
        		cb++;
        	} else if( ca == 0) {
        		a = nums[i];
        		ca = 1;
        	} else if(cb == 0) {
        		b = nums[i];
        		cb = 1;
        	} else {
        		ca--;
        		cb--;
        	}
        }

        ca = 0; cb = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] == a) {
        		ca++;
        	} else if(nums[i]== b) {
        		cb++;
        	}
        }
        std::vector<int> vRet;

        if(ca*3 > nums.size()) {
        	vRet.emplace_back(a);
        }
        if(cb*3 > nums.size()) {
        	vRet.emplace_back(b);
        }
        return vRet;
    }
};