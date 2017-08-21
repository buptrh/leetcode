class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        helper(ret, s, path, 0);
        return ret;
    }

    void helper(vector<vector<string>> & ret, string & s, vector<string> & path, int pos) {
    	if(pos >= s.size()) {
    		ret.emplace_back(path);
    		return;
    	}
    	for(int i = pos; i < s.size(); i++) {
    		if(isPalindrome(s.substr(pos, i-pos+1))) {
    			path.emplace_back(s.substr(pos, i-pos+1));
    			helper(ret, s, path, i+1);
    			path.pop_back();
    		}
    	}
    }

    bool isPalindrome(string  s) {
    	if(s.size() == 0) {
    		return false;
    	}
    	for(int i = 0; i <= s.size()/2; i++) {
    		if(s[i] != s[s.size()-1-i]) {
    			return false;
    		}
    	}
    	return true;
    }
};