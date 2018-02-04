class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0) {
    		return INT_MAX;
    	} else if(dividend) {
    		// return 0;
    	}
        long long de = labs(dividend);
        long long di = labs(divisor);
        cout<<de<<". " << di<<endl;
    	bool sign = ((dividend < 0) ^ (divisor < 0)) ? true : false;
        long long multi = 1, div = di, res = 0;
        while(de >= div) {
        	multi = multi << 1;
        	div = div << 1;
        }
        if(de >= div) {
		    de -= div;
		    res += multi;
        }
        cout << de << endl;
        while(de != 0 && div > de && div > di) {
        	multi = multi >> 1;
        	div = div >> 1;
        	if(de >= div) {
        		de -= div;
        		res += multi;
        	}
        	if(de == 0) {
        		break;
        	}
        }
        cout << res << endl;
    	return sign ? -(int)res : res;
    }
};