class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        char ret = t[s.size()];
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] != t[i]) {
        		ret = t[i];
        		return ret;
        	}
        }
        ret = t[s.size()];
        return ret;
    }
};


//

class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};