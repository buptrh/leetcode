//10:47
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check = (n&1 == 1);
        while(n != 0) {
        	if((n&1 == 1) == check) {
        		check = !check;
        	} else {
        		return false;
        	}
        	n = n>>1;
        }
        return true;
    }
};
//10:55