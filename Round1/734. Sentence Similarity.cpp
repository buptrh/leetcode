class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size() ) {
        	return false;
        }
        map<string, set<string>> similiar;
        for(auto p : pairs) {
        	similiar[p.first].insert(p.second);
        }

        for(int i = 0; i < words1.size(); i++) {
        	string s1 = words1[i];
        	string s2 = words2[i];
        	if(s1 == s2 || (similiar[s1].find(s2) != similiar[s1].end())
        					 || similiar[s2].find(s1) != similiar[s2].end()) {
        		continue;
        	} else {
        		return false;
        	}
        }
        return true;
    }
};