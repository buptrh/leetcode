//Not finished
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	return helper(s, wordDict );
    }

    bool helper(string s, vector<string>& wordDict) {
    	vector<string> ret;
		for(int j = 0; j < wordDict.size(); j++) {
			if(s.substr(0, wordDict[j].size()) == wordDict[j]) {
				if(s.size() == wordDict[j].size()) {
					return true;
				} else {
					if(helper(s.substr(wordDict[j].size()), wordDict)) {
						return true;
					}
				}
			}
		}
    	return false;
    }
};