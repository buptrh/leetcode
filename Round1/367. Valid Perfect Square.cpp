// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False
class Solution {
public:
    bool isPerfectSquare(int num) {
    	int start = 1, end = num;
    	long mid = 0;
    	while(start <= end) {
    		mid = (end + start)/2;
    		long multi = mid * mid;
    		if(multi == num) {
    			return true;
    		} else if(multi > num) {
    			end = mid - 1;
    		} else {
    			start = mid + 1;
    		}
    	}
    	return false;

    }
};