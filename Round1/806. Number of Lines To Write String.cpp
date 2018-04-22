class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
    	if(S.size() == 0) {
	        res.push_back(0);
	        res.push_back(0);
    		return res;
    	}
    	int lines = 1, last = 0;
        for(int i = 0; i < S.size(); i++) {
        	if(last + widths[S[i] - 'a'] > 100) {
        		last = 0;
        		lines ++;
        	}
        	last += widths[S[i] - 'a'];
        }
        res.push_back(lines);
        res.push_back(last);
        return res;
    }
};