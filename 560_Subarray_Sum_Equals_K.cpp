class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sumMap;
        int sum = 0, found = 0;
        sumMap[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
        	sum += nums[i];
    		found = found + sumMap[sum-k];
    		sumMap[sum] = ++;
        }
        return found;
    }
};


//be careful