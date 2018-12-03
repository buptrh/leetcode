class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    	vector<string> res;
        for(string s : words) {
        	if(s.size() != pattern.size()) {
        		continue;
        	}
        	unordered_map<char, char> table;
        	unordered_map<char, char> table2;
        	bool flag = true;
        	for(int i = 0; i < pattern.size(); i++) {
        		char c = s[i];
        		if(table.find(pattern[i]) == table.end() && table2.count(c) == 0) {
        			table[pattern[i]] = c;
        			table2[c] = pattern[i];
        		} else if(table[pattern[i]] == c && table2.count(c) == 1) {
        			continue;
        		} else {
        			flag = false;
        			break;
        		}
        	}
        	if(flag) {
        		res.push_back(s);
        	}
        }
        return res;
    }
};