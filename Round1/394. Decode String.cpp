class Solution {
public:
    string decodeString(string s) {
    	return helper(s, 0, s.size()-1);
    }

    string helper(string & s, int start, int end) {
        string ret;
    	int flag = 0;
    	int index = -1;
    	int multi = 0;
        for(int i = start; i <= end; i++) {
        	if(s[i] == '[') {
        		if(flag == 0) {
        			index = i;
        		}
        		flag ++;
        	} else if(s[i] == ']') {
        		flag --;
        		if(flag == 0) {
        			string ret2 = helper(s, index+1, i-1);
        			for(int j = 0; j < multi; j++) {
        				ret += ret2;
        			}
        			index = -1;
        			multi = 0;
        		}
        	} else if(flag == 0) {
        		if(s[i] >= '0' && s[i] <= '9') {
        			multi = multi*10 + s[i] - '0';
        			// cout<< " multi: " << multi<<endl;
        		} else {
        			if(multi == 0) {
        				multi = 1;
        			}
        			// cout<<"word: " << multi << "  "  << s[i] <<endl;
        			for(int j = 0; j < multi; j++) {
        				ret += s[i];
        			}
        			multi = 0;
        		}
        	}
        }
        return ret;
    }
};