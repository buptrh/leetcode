class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0;
        int res = 0;
        map<char, int> table;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(table[s[i]] == 0) {
        		count++;
        	}
        	table[s[i]]++;
        	while(count > 2) {
        		table[s[left]]--;
        		if(table[s[left]] == 0) {
        			count --;
        		}
        		left++;
        	}
        	res = max(res, i - left + 1);
        }
        return res;
    }
};