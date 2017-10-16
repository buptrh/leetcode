class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros = 0, ones = 0, prevZeros = 0, prevOnes = 0, ret = 0;
        for(char c : s) {
        	if(c == '0') {
        		if(zeros == 0) {
        			prevOnes = ones;
        			ones = 0;
        		}
        		zeros++;
        		if(zeros <= prevOnes) {
        			ret++;
        		}
        	} else {
        		if(ones == 0) {
        			prevZeros = zeros;
        			zeros = 0;
        		}
        		ones++;
        		if(ones <= prevZeros) {
        			ret++;
        		}
        	}
        }
        return ret;
    }
};