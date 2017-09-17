class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1, mid;
        vector<int> ret;
        while(left < right) {
        	if(numbers[left] + numbers[right] == target) {
        		ret.emplace_back(left+1);
        		ret.emplace_back(right+1);
        		return ret;
        	} else if(numbers[left] + numbers[right] < target) {
        		left++;
        	} else {
        		right--;
        	}
        }
        return ret;
    }
};