// We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
// Note: The length of the input array will not exceed 20,000.

// Discuss


class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<int> big(nums.size(), 0);
        vector<int> equ(nums.size(), 1);
        vector<int> sma(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] == nums[i]) {
                    equ[i] ++;
                    equ[j] ++;
                } else if(nums[j] == nums[i] + 1) {
                    sma[i] ++;
                    big[j] ++;
                } else if(nums[i] == nums[j] + 1) {
                    big[i] ++;
                    sma[j] ++;
                }
            }
         }
        int maxValue = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(big[i] != 0 || sma[i] != 0) {
                maxValue = max(maxValue, max(big[i], sma[i]) + equ[i] );
            }
        }
        return maxValue;
    }
};