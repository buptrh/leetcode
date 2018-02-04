class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int maxV = INT_MIN, prev = INT_MIN;
        bool res = true;
        for(int i = 0; i < A.size(); i++) {
        	if(prev > A[i]) {
        		return false;
        	} else {
        		prev = maxV;
        		maxV = max(maxV, A[i]);
        	}
        }
        return true;
    }
};