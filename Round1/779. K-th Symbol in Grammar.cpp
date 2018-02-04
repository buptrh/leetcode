class Solution {
public:
    int kthGrammar(int N, int K) {
        if(K == 1) {
        	return 0;
        }
        int i = 2;
        bool flag = true;
        K--;
        while(K > 0) {
        	i = 1;
	        while(i*2 <= K) {
	        	i *= 2;
	        }
        	if(K >= i) {
	        	K = K - i;
    			flag = !flag;
        	}
        }
	    return flag ? 1 : 0;
    }
};