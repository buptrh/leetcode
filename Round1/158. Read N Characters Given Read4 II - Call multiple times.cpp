// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
	char* buffer = NULL;
	int size = 0;
	int current = 0;
	bool finish = false;
    int read(char *buf, int n) {
    	if(n == 0) {
    		return 0;
    	}
    	if(current + n <= size) {
			// buf = new char[n];
			memcpy(buf, buffer+current, n);
			current += n;
			return n;
		}	

    	if(finish) {
			int res = size - current;
			if(res != 0) {
				memcpy(buf, buffer+current, res);
			}
			current = size;
			return res;
    	}

    	int target = ((current + n)/4)*4;
    	if((current + n)%4 > 0) {
    		target += 4;
    	}
		char * newbuf = new char[target];
		if(size > 0) {
			memcpy(newbuf, buffer, size);
	    	delete [] buffer;
		}
    	buffer = newbuf;
    	newbuf += size;
    	int c = read4(newbuf);
    	while(c >= 4 && size+c < target) {
    		size += c;
    		newbuf += c;
    		c = read4(newbuf);
    	}
		size += c;
		newbuf += c;
    	if(c < 4) {
    		finish = true;
    	}
    	return read(buf, n);
    }
};