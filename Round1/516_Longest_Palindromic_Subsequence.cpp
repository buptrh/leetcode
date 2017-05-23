class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length() == 0 || s.length() == 1) {
        	return s.length();
        }
        int p[s.length()][s.length()] = {0};

        for(int i = s.length()-1; i >= 0; i --) {
        	p[i][i] = 1;
        	for( int j = i+1; j < s.length(); j++) {
        		if (s[i] == s[j]) {
        			p[i][j] = p[i+1][j-1] + 2;
        		} else {
        			p[i][j] = max(p[i+1][j], p[i][j-1]);
        		}
        	}
        }
        return p[0][s.length()-1];
    }
};


//dynamic programming
