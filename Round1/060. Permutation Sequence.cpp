class Solution {
public:
    string getPermutation(int n, int k) {
    	int total = 1;
    	for(int i = 1; i <= n; i++) {
    		total *= i;
    	}

    	string ret;
    	int table[9];
    	for(int i = 0; i < 9; i ++) {
    		table[i] = 0;
    	}
    	for(int i = n; i >= 1; i--) {
    		int val = (k-1)/(total/i);
    		// cout<<val << "  " << k << "  " << total <<endl;
    		k = (k-1) % (total/i)+1;
    		total /= i;
    		if(k == 0) {
    			val = 0;
    		}
    		for(int j = 0; j < 9; j ++) {
    			if(table[j] == 0) {
    				val --;
    			}

    			if(table[j] == 0 && val < 0) {
    				ret += j + '1';
    				table[j] = 1;
    				break;
    			}
    		}
    	}
    	return ret;
    }
};