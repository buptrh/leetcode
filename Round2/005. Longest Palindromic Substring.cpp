class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) {
            return s;
        }
        int len = 0, lo = 0;
        for(int i = 0; i < s.size(); i++) {
            int temp = helper(s, i, i);
            if(len < temp) {
                len = temp;
                lo = i - len/2;
            }
            temp = helper(s, i, i+1);
            if(len < temp) {
                len = temp;
                lo = i - len/2+1;
            }
        }
    	
        return s.substr(lo, len);
    }

    int helper(string & s, int start, int end) {
        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        cout<< start << end << endl;
        return end - start - 1;
    }
};