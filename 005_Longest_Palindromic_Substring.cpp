class Solution {
public:
    string longestPalindrome(string s) {
    	int max_length = 0, max_front = 0;
        for(int i = 0; i < s.size(); i++) {
      		if (s.size() - i <= max_length / 2) {
      			break;
      		}
      		int endstart = s.size()-1;
        	int front = i, end = endstart;
        	while(front < end){
        		if(front == i) {
        			while( end > front && s[end] == s[front] && s[end] == s[i]) {
        				front++;
        				end--;
        			}
        			if(front > i) {
            			while( front < end  && s[end] == s[i] ) {
            				endstart--;
        					end = endstart ;
            			}
        			}
        		}
    			if(front >= end) {
    				break;
    			}
        		if(s[front] != s[end]) {
        			endstart --;
        			end = endstart;
        			front = i;
        		} else {
        			front++;
        			end--;
        		}
        	}
        	int length = 2 * (front - i);
        	if(end == front) {
        		length ++;
        	} else {

        	}
        	if(max_length < length) {
        		max_length = length;
        		max_front = i;
        	}
        }
        return s.substr(max_front, max_length);
    }
};