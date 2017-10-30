class Solution {
public:
    int compress(vector<char>& chars) {
    	if(chars.size() <= 1) {
    		return chars.size();
    	}
    	int ret = 1;
    	int last = chars[0], count = 1;
        for(int i = 1; i < chars.size(); i++) {
        	char c = chars[i];
        	if((int)c != last) {
        		if(count > 1) {
        			vector<int> output;
        			while(count != 0) {
        				output.push_back('0' + count%10);
        				count /= 10;
        			}
        			for(int m = output.size()-1; m >= 0; m--) {
        				chars[ret] = output[m];
        				ret++;
        			}
        		}
        		chars[ret] = c;
        		ret++;
        		count = 1;
        	} else {
        		count++;
        	}
        	last = (int)c;
        }
        if(count > 1) {
			vector<int> output;
			while(count != 0) {
				output.push_back('0' + count%10);
				count /= 10;
			}
			for(int m = output.size()-1; m >= 0; m--) {
				chars[ret] = output[m];
				ret++;
			}
		}
        return ret;
    }
};