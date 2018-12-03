class Solution {
public:

    bool isValid(string & time) {
        if ((time[3] - '0') * 10 + (time[4] - '0') >= 60|| (time[0] - '0') * 10 + (time[1] - '0') >= 24) {
            return false;
        }
        return true;
    }
    string nextClosestTime(string time) {
        vector<char> chars;
        for(int i = 0; i < time.size(); i++) {
        	if(time[i] != ':') {
        		chars.push_back(time[i]);
        	}
        }
        sort(chars.begin(), chars.end());
        string ret(time);
        bool flag = false;
        for(int i = time.size()-1; i >= 0; i--) {
        	if(time[i] == ':') {
        		continue;
        	}
        	int pos = -1;
    		for(int j = 0; j < chars.size(); j++) {
    			if(chars[j] == time[i]) {
    				pos = j;
    				break;
    			}
    		}
         	if(pos == 0) {
                int last = chars.size()-1;
                ret[i] = chars[last];
                while(last >= pos && !isValid(ret)) {
                    last--;
                    ret[i] = chars[last];
                }
        	} else {
        		ret[i] = chars[pos-1];
                break;
        	}
        }
        return ret;
    }

};