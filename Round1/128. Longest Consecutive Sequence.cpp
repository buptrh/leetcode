class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
        	s.insert(nums[i]);
        }
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
        	if(s.find(nums[i]) == s.end()) {
        		continue;
        	}
        	int left = nums[i]-1, right = nums[i]+1;
        	while(s.find(left) != s.end()) {
        		s.erase(left);
        		left--;
        	}
        	while(s.find(right) != s.end()) {
        		s.erase(right);
        		right++;
        	}
        	ret = max(ret, right-left-1);
        }
        return ret;
    }
};