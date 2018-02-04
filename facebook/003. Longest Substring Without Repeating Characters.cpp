class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dup;
        int left = 0, res = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(dup.find(s[i]) != dup.end()) {
        		left = max(left, dup[s[i]]+1);
        	}
        	dup[s[i]] = i;
        	res = max(res, i - left + 1);
        }
        return res;
    }
};