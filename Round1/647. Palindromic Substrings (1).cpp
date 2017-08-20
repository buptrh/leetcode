class Solution {
public:
    int countSubstrings(string s) {
    	set< pair<int, int> > pad;
    	int left = 0, right = 0;
    	bool flag = false;
        for(int i = 0; i < s.size(); i++) {
        	for(int j = i; j < s.size(); j++) {
        		flag = true;
        		if(pad.find(pair<int, int>(i,j)) != pad.end()) {
        			continue;
        		} else {
        			left = i;
        			right = j;
        			while(left < right) {
        				if(s[left] != s[right] ) {
        					flag = false;
        					break;
        				}
        				left++;
        				right--;
        			}
        			if(flag) {
        				pad.insert(pair<int, int>(i,j));
        			}
        		}
        	}
        }
        return pad.size();
    }
};