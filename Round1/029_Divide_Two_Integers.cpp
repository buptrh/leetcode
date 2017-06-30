class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
    		return INT_MAX;
    	}
    	long long ldividend = dividend;
    	long long ldivisor = divisor;
    	bool minus = false;
    	if( (ldividend <= 0 && ldivisor < 0) || (ldividend >= 0 && ldivisor > 0 )) {
    		minus = false;
    	} else {
    		minus = true;
    	}
		ldividend = labs(ldividend);
		ldivisor = labs(ldivisor);
        long long ret = 0, temp = ldivisor, multiple = 1;
        while(ldividend >= ldivisor) {
        	temp = ldivisor, multiple = 1;
        	while(ldividend >= temp << 1) {
        		temp <<= 1;
        		multiple <<= 1;
        	}
        	ldividend -= temp;
        	ret += multiple;
        }
        return (int)(minus ? -ret : ret);
    }
};



//copied from
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};