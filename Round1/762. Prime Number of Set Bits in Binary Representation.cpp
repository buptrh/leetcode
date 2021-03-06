class Solution {
public:
    int countPrimeSetBits(int L, int R) {
    	unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,};
    	int res = 0;
        for(int i = L; i <= R; i++) {
        	int count = 0;
        	int num = i;
        	while(num > 0) {
        		if(num & 1 != 0) {
        			count++;
        		}
        		num = num >> 1;
        	}
        	if(primes.count(count)) {
        		res++;
        	}
        }
        return res;
    }
};