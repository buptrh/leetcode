class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = -1;
        int ret = 0;
        for(int i = 0; i < A.size(); i++) {
        	if (A[i] > max) {
        		ret = i;
        		max = A[i];
        	}
        }

        return ret;
    }
};