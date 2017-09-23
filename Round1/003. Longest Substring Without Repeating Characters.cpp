class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	map<char, int> table;
    	int start = 0, ret = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(table.find(s[i]) != table.end()) {
        		if(table[s[i]] >= start) {
        			ret = max(ret, i - start);
        			start = table[s[i]] + 1;
        		}
        	}
    		table[s[i]] = i;
        }

        ret = max(ret, (int)s.size() - start);
        return ret;
    }
};