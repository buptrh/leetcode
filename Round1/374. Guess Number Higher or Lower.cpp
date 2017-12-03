// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber (int n) {
    	int start = 1, end = n, mid;
    	while(start + 1 < end) {
    		mid = start + (end - start) / 2;
    		int val = guess(mid);
    		if(val == 0) {
    			return mid;
    		} else if(val > 0) {
    			start = mid;
    		} else {
    			end = mid;
    		}
    	}
    	if(guess(start) == 0) {
    		return start;
    	} else {
    		return end;
    	}
     }
};