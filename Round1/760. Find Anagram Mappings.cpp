class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> table;
        for(int i = 0; i < B.size(); i++) {
        	table[B[i]].push_back(i);
        }

        vector<int> res;
        for(int i = 0; i < A.size(); i++) {
        	// cout<<table[B[i]].back()<<endl;
        	res.push_back((table[A[i]].back()));
        	table[A[i]].pop_back();
        }
        return res;

    }
};