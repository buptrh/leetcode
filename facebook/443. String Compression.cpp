class Solution {
public:
    int compress(vector<char>& chars) {
    	int pos = 0, count = 0;
    	char c = 0;
        for(int i = 0; i < chars.size(); i++) {
        	if(chars[i] != c) {
        		pos += setCount(chars, pos, count);
        		c = chars[i];
        		chars[pos] = c;
        		pos++;
        		count = 1;
        	} else {
        		count++;
        	}
        }
		pos += setCount(chars, pos, count);
		return pos;
    }

    int setCount(vector<char> & chars, int pos, int count) {
    	if(count == 1) {
    		return 0;
    	}
    	int size = 0, temp = count;
    	while(temp != 0) {
    		size++;
    		temp /= 10;
    	}
    	for(int i = pos + size - 1; i >= pos; i--) {
    		chars[i] = '0' + count % 10;
    		count /= 10;
    	}

    	return size;
    }
};