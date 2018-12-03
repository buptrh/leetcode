class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalA = 0, totalB = 0;
        vector<int> res;
        for(int i : A) {
        	totalA += i;
        }
        for(int i : B) {
        	totalB += i;
        }
        for(int i = 0; i < A.size(); i++) {
        	for(int j = 0; j < B.size(); j++) {
        		if(totalA - A[i] + B[j] == totalB - B[j] + A[i]) {
        			res.push_back(A[i]); 
        			res.push_back(B[j]); 
        			return res;
        		}
        	}
        }
        return res;
    }
};