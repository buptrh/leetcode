class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for(int i = 0; i <= s.size(); i ++) {
        	if(i == s.size() || s[i] == ' ' ) {
        		for(int j = 0; j <= (i-1 - start) / 2; j++) {
        			swap(s[start+j], s[i-1-j]);
        		}
        		start = i+1;
        	}
        }
        return s;
    }
};