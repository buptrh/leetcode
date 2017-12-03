class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	if(nums.size() == 0) {
    		return 0;
    	}
    	int index = 0, preSize = 0, maxCount = 0, curSize = 0;
    	unordered_set<int> numSets;
    	for(int i = 0; i < nums.size(); i++) {
    		index = i;
    		preSize = 0;
    		curSize = numSets.size();
	        while(true){
	    		numSets.insert(index);
	    		if(preSize == numSets.size()-curSize) {
	    			maxCount = max(maxCount, preSize);
	    			break;
	    		}
	    		preSize++;
	    		index = nums[index];
	        }
    	}
        return maxCount;
    }
};