class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.empty()) {
    		return 0;
    	} else if(haystack.size() < needle.size()) {
    		return -1;
    	}
        int index = 0, n = needle.size();
        for(int i = 0; i < haystack.size() - n+1; i++) {
        	while(index != n) {
        		if(haystack[i+index] == needle[index]) {
        			index++;
        		} else {
        			break;
        		}
        	}
        	if(index == n) {
        		return i;
        	} else {
        		index = 0;
        	}
        }
        return -1;
    }
};