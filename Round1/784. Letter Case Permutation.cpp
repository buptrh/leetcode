class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        for(int i = 0; i < S.size(); i++) {
        	if(S[i] >= 'A' && S[i] <= 'Z') {
        		S[i] = S[i] - 'A' + 'a';
        	}
        }
        unordered_set<string> res;
        helper(S, 0, res);
        vector<string> rrr;
        for(string s : res) {
        	rrr.emplace_back(s);
        }
        return rrr;
    }

    void helper(string & S, int pos, unordered_set<string> & res) {
    	res.insert(S);
    	for(int i = pos; i < S.size(); i++) {
    		// cout<< pos << "  " << S <<  endl;
        	if(S[i] >= 'a' && S[i] <= 'z') {
	    		S[i] = S[i] + 'A' - 'a';
	    		helper(S, pos+1, res);
	    		S[i] = S[i] - 'A' + 'a';
	    	}
    	}
    }
};