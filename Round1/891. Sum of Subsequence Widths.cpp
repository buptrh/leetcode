
#define MOD 1000000007
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        long long res = 0;
        static unordered_map<int, long long> table;
		table[0] = 1;
		if(table[500] < 2) {
			for(int i = 1; i <= 20000; i++) {
				table[i] = table[i-1]*2;
	    		table[i] = table[i] % MOD;
			}
		}
        for(int i = 0; i < A.size(); i++) {
        	for(int j = A.size()-1; j > i; j--) {
        		res += (A[j] - A[i]) * table[j-i-1];
        		res = res % MOD;
        	}
        }
        return res;
    }
};