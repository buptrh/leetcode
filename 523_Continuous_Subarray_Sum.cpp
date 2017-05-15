class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	if(nums.size() <= 1) {
    		return false;
    	}
    	int arraySize = k;
    	if(k < 0) {
    		arraySize = 0-k;
    		k = 0-k;
    	}  else if (k == 0) {
    		arraySize = 1;
    	}
    	if(k > nums.size()) {
    		arraySize = nums.size();
    	}
        vector<int> sums(arraySize,-1);
        for(int i = 0; i < nums.size(); i++) {
        	int cur = nums[i];
        	for(int j = 0; j < arraySize; j++) {
        		if(sums[j] >= 0) {
        			if(k != 0) {
        				sums[j] = (sums[j] + cur) % k;
        			} else {
        				sums[j] = sums[j] + cur;
        			}
        			if(sums[j] == 0) {
        				return true;
        			}
        		} else {
        			sums[j] = cur;
        			break;
        		}
        	}
        }
        return false;
    }
};


//use hashset to store sums. so that we can use contains.
//unordered_set
//sum of items (from a to b) is all items from 0 to b, minus items from 0 to a

//pay attention to edge data; for example: k = 0 , k < 0, k > size;
// Some damn it! test cases:
// [0], 0 -> false;
// [5, 2, 4], 5 -> false;
// [0, 0], 100 -> true;
// [1,5], -6 -> true;


