class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	if(n == 1 || n == 0) {
    		return n;
    	}
        int point[primes.size()] = {0};
        int val[n];
        val[0] = 1;
        for(int i = 1; i < n; i++) {
        	val[i] = INT_MAX;
        }
        int index = 0;
        for( int i = 1; i < n; i++ ) {
        	int min = 0;
        	for(int j = 0; j < primes.size(); j++) {
        		val[i] = min(val[i], val[point[j]] * primes[j]);
        	}
        	for(int j = 0; j < primes.size(); j++) {
        		if(val[i] == val[point[j]] * primes[j]) {
        			point[j] ++;
        		}
        	}
        }
        return val[n-1];
    }
};

//there are two solutions about this question:
// 1. like solution above. o(k*n). but we can improve the performance by not multipling val and prime many times. we can save it in last loop.
// 2. use heap sort. like #264. sort is o(log(k)). but need to sort n times. so totally it's o(n*k*log(k)). slower.