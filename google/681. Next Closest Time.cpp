class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> chars;
        for(int i = 0; i < time.size(); i++) {
        	if(time[i] <= '9' && time[i] >= '0') {
        		chars.push_back(time[i]);
        	}
        }
        sort(chars.begin(), chars.end());
        string ret(time);
        bool flag = false;
        for(int i = time.size()-1; i >= 0; i--) {
        	if(time[i] > '9' || time[i] < '0') {
        		continue;
        	}
        	int pos = -1;
    		for(int j = chars.size()-1; j >= 0; j--) {
    			if(chars[j] == time[i]) {
    				pos = j;
    				break;
    			}
    		}
         	if(pos == chars.size()-1) {
        		ret[i] = chars[0];
        	} else {
        		ret[i] = chars[pos+1];
        		if (ret[3] >= '6' || (ret[0] - '0') * 10 + (ret[1] - '0') >= 24) {
        			ret[i] = chars[0];
        		} else {
        			break;
        		}
        	}
        }
        return ret;
    }
};