class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        bool flag = false, finish = true;
        while(start < end) {
        	if(s[start] != s[end]) {
        		if(flag) {
        			finish = false;
        			break;
        		}
        		start++;
        		flag = true;
        		continue;
        	}
        	start++;
        	end--;
        }
        if(finish) {
        	return true;
        }

        start = 0, end = s.size()-1;
        flag = false, finish = true;
        while(start < end) {
        	if(s[start] != s[end]) {
        		if(flag) {
        			finish = false;
        			break;
        		}
        		end--;
        		flag = true;
        		continue;
        	}
        	start++;
        	end--;
        }

        return finish;

    }
};