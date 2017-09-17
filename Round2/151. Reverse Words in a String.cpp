class Solution {
public:
    void reverseWords(string &s) {
    	int start = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == ' ') {
        		if(start >= i) {
        			s.erase(i, 1);
        			i--;
        		} else {
        			helper(s, start, i-1);
        		}
        		start = i+1;
        	}
        }
        while(s[s.size()-1] == ' ') {
        	s.pop_back();
        }
        helper(s, start, s.size()-1);
        reverse(s.begin(), s.end());
    }

    void helper(string & s, int start, int end) {
    	while(start < end) {
    		swap(s[start], s[end]);
    		start++;
    		end--;
    	}
    }
};