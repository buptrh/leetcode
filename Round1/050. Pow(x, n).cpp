// Implement pow(x, n).
class Solution {
public:
    double myPow(double x, int n) {
    	double ret = 1;
        while(n > 0) {
        	ret *= x;
        	n--;
        	if(abs(ret) < 1e-7 || abs(ret-1.0) < 1e-7) {
        		break;
        	}
        	if( abs(ret + 1.0) < 1e-7 ) {
        		if(n % 2 == 0) {
        			ret = -1;
        		} else {
        			ret = 1;
        		}
        		break;
        	}
        	// cout<<ret<<endl;
        }
        while(n < 0) {
        	ret /= x;
        	n++;
        	if(abs(ret) < 1e-7 || abs(ret-1.0) < 1e-7 ) {
        		break;
        	}
        	if( abs(ret + 1.0) < 1e-7 ) {
        		if(n % 2 == 0) {
        			ret = -1;
        		} else {
        			ret = 1;
        		}
        		break;
        	}
        }
        return ret;
    }
};


//best solution is o(log(n)) use square recuisive