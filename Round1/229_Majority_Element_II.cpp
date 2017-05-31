class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> vRet;
        std::vector<int> vTest;
        for(int i = 0; i < nums.size()*2/3; i++) {
        	if(nums[i] == nums[i+nums.size()/3]) {
        		vTest.emplace_back(nums[i]);
        	}
        }

        for(int i = 0; i < nums.size(); i++) {
        	
        }

    }
};