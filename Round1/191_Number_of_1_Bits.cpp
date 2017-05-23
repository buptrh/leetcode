class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int count = 0;
        while(n != 0) {
        	if(n%2 != 0) {
        		count++;
        	}
        	n = n >> 1;
        }
        return count;
    }
};


//n % 2 == n & 1
// better Solution
// int res = 0;
//     while(n)
//     {
//         n &= n - 1;
//         ++ res;
//     }
//     return res;