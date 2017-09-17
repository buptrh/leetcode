class Solution {
public:
    int arrangeCoins(int n) {
        int count = 1, ret = 0;
        while(n >= count) {
        	n -= count;
        	count++;
        	ret++;
        }
        return ret;
    }
};
