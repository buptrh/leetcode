class Solution {
public:
    int smallestFactorization(int a) {
    	if( a == 1) {
    		return 1;
    	}
    	std::vector<int> v;
        for(int i = 9; i >= 2; i--) {
        	while(a%i == 0) {
        		v.emplace_back(i);
        		a = a/i;
        	}
        }

        sort(v.begin(), v.end());
        int val = 0;
        if( a == 1) {
	        for(int i = 0; i < v.size(); i++) {
	        	if(val > INT_MAX/10) {
	        		return 0;
	        	}
	        	val = val * 10 + v[i];
	        }
        } else if( a < 10) {
        	val = a;
        }
        return val;
    }
};