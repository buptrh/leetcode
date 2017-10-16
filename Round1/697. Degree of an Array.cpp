class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxVal = 0;
        vector<int> maxIndex;
        map<int, int> table;
        for(int n : nums) {
        	table[n]++;
        	if(table[n] > maxVal) {
        		maxIndex = std::vector<int>();
        		maxIndex.push_back(n);
        		maxVal = table[n];
        	} else if(maxVal == table[n]) {
        		maxIndex.push_back(n);
        	}
        }
        vector<int> end(maxIndex.size(), 0), start(maxIndex.size(), nums.size()-1);
        int ret = nums.size();
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = 0; j < maxIndex.size(); j++) {
        		if(nums[i] == maxIndex[j]) {
	        		end[j] = max(end[j], i);
	        		start[j] = min(start[j], i);
        		}
        	}
        }

        for(int i = 0; i < maxIndex.size(); i++) {
        	ret = min(ret, end[i] - start[i] + 1);
        }
        return ret;
    }
};