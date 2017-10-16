class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	string path;
    	std::vector<string> ret;

        helper(n, n, "", ret);
        return ret;
    }

    void helper(int left, int right, string  path, vector<string> & ret) {
    	if(left == 0 && right == 0) {
    		ret.emplace_back(path);
    		return;
    	}
    	string s1;
    	for(int i = 0; i <= left; i++) {
    		if(right-1 > left-i) {
    			s1 += "(";
    			continue;
    		}
			s1 += ")";
    		if(right > 0) {
    			helper(left - i, right-1, s1 + path, ret);
    		}
    		s1.pop_back();
			s1 += "(";
    	}	
    }

};