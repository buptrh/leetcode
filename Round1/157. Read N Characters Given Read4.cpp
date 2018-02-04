// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	int sum = 0;
    	int count = 0;
        while(true) {
        	count = read4(buf + sum);
        	sum += count;
        	if(count < 4 || sum >= n) {
        		break;
        	}
        }
        return min(sum, n);
    }
};