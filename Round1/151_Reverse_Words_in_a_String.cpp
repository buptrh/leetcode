class Solution {
public:

    void reverseWords(string &s) {
    	if(s.size() == 0) {
    		return;
    	}
        int pos = 0;
        int pos_next = s.find(" ");
        while(pos_next >= pos) {
        	if(pos_next == pos) {
        		s.erase(pos, 1);
        	} else {
        		reverse(s.begin() + pos, s.begin() + pos_next);
        		pos = pos_next+1;
        	}
        	pos_next = s.find(" ", pos);
        }
        
    	if(s.size() == 0) {
    		return;
    	}
        if(pos == s.size()) {
        	s.erase(pos-1, 1);
        } else {
        	reverse(s.begin()+pos, s.end());
        }
        reverse(s.begin(), s.end());
    }
};