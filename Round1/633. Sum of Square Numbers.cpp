class Solution {
public:
    bool judgeSquareSum(int c) {
    	// cout<<sqrt(c);
        for(long long i = 0; i <= sqrt(c); i++) {
        	long long val = (long long)c - i*i;
        	long long root = sqrt(val) + 0.5;
        	if(root * root == val) {
        		return true;
        	}
        }
        return false;
    }
};