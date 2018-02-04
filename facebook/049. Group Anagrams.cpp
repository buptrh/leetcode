class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string, vector<string>> strsMap;
        for(string s : strs) {
        	string temp = s;
        	sort(temp.begin(), temp.end());
        	strsMap[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto & vec : strsMap) {
        	res.push_back(vec.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	 vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};//最多10609
    	 unordered_map<int, vector<string>> strsMap;
        for(string s : strs) {
        	int k = 1;
        	for(char c : s) {
        		k *= prime[c - 'a'];
        	}
        	strsMap[k].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it = strsMap.begin(); it != strsMap.end(); it++) {
        	res.push_back(it->second);
        }
        return res;
    }
};