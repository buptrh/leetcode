class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> table;
        for(int i = 0; i < s.size(); i++) {
        	table[s[i]]++;
        }

        int ret = 0;
        bool flag = false;
        for(auto it = table.begin(); it != table.end(); it++) {
        	ret += ((it->second)/2)*2;
        	if(!flag && it->second%2 != 0) {
        		flag = true;
        	}
        }

        if(flag) {
        	ret++;
        }
        return ret;
    }
};