class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	map<string, vector<string>> table;
    	return helper(s, wordDict, table);
    }

    bool helper(string s, vector<string>& wordDict, map<string, vector<string>>& table) {
    	if(table.find(s) != table.end()) {
    		// cout<<s << ":  " << table[s].size()<<endl;
    		return table[s];
    	}
    	vector<string> ret;
		for(int j = 0; j < wordDict.size(); j++) {
			if(s.substr(0, wordDict[j].size()) == wordDict[j]) {
				if(s.size() == wordDict[j].size()) {
					return true;
				} else {
					if(helper(s.substr(wordDict[j].size()), wordDict, table)) {
						return true;
					}
					for(int i = 0; i < sub.size(); i++) {
						ret.emplace_back(wordDict[j] + " " + sub[i]);
					}
				}
			}
		}
    	table[s] = ret;
    	return false;
    }
};