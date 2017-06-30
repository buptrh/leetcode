class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int length = A.size();
        unordered_map<int, int> table;
        int ret = 0;
        if(length <= 0) {
        	return ret;
        }

        long long target = 0;
        for(int i = 0; i < length; i++) {
        	for(int j = 0; j < length; j++) {
        		table[A[i]+B[j]] ++;
        	}
        }

        for(int i = 0; i < length; i++) {
        	for(int j = 0; j < length; j++) {
        		ret += table[0-C[i]-D[j]];
        	}
        }
        return ret;
    }
};

// copied from discuss. faster
 int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>  abSum;
        for(auto a : A) {
            for(auto b : B) {
                ++abSum[a+b];
            }
        }
        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = abSum.find(0 - c - d);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }