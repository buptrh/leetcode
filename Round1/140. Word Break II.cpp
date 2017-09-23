class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	map<string, vector<string>> table;
    	return helper(s, wordDict, table);
    }

    vector<string> helper(string s, vector<string>& wordDict, map<string, vector<string>>& table) {
    	if(table.find(s) != table.end()) {
    		// cout<<s << ":  " << table[s].size()<<endl;
    		return table[s];
    	}
    	vector<string> ret;
		for(int j = 0; j < wordDict.size(); j++) {
			if(s.substr(0, wordDict[j].size()) == wordDict[j]) {
				if(s.size() == wordDict[j].size()) {
					ret.emplace_back(wordDict[j]);
				} else {
					vector<string> sub = helper(s.substr(wordDict[j].size()), wordDict, table);
					for(int i = 0; i < sub.size(); i++) {
						ret.emplace_back(wordDict[j] + " " + sub[i]);
					}
				}
			}
		}
    	table[s] = ret;
    	return ret;
    }
};