class Solution {
public:
    bool isAlphanumeric(char letter) {
    	if ( (letter >= '0' && letter <= '9') || (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') )
    	{
    		return true;
    	}
    	return false;
    }
    bool isPalindrome(string s) {
    	if(s.size() == 0 || s.length() == 1 ){
    		return true;
    	}
        int front = 0, end = s.length()-1;
        while(front < end) {
        	while( front <= end && !isAlphanumeric(s[front] ) ){
        		front++;
        	}
        	while(end >= front && !isAlphanumeric(s[end]) ){
        		end--;
        	}
        	if(front < end && s[front] != s[end] &&  !( ( s[front] >='a' && s[front] <= 'z' && s[end] == s[front] + 'A' - 'a') || ( s[front] >='A' && s[front] <= 'Z' && s[end] == s[front] + 'a' - 'A') ) ) {
        		return false;
        	} else {
        		front++;
        		end--;
        	}
        }
        return true;
    }

};