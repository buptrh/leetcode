//http://www.1point3acres.com/bbs/thread-285861-1-1.html
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        vector<string> path;
        path.emplace_back(beginWord);
        vector<bool> visited(wordList.size(), false);
        int min_level = INT_MAX;
        helper(beginWord, endWord, wordList, path, visited, ret, min_level);

        vector<vector<string>> ret2;
        for(int i = 0; i < ret.size(); i++) {
        	if((int)ret[i].size() == min_level) {
        		ret2.emplace_back(ret[i]);
        	}
        }
        return ret2;
    }
    void helper(string beginWord, string endWord, vector<string>& wordList, vector<string>& path, vector<bool> & visited, vector<vector<string>>& ret, int & min_level) {
    	if((int)path.size() > min_level) {
    		return;
    	}
    	if(beginWord == endWord) {
    		ret.emplace_back(path);
    		min_level = min(min_level, (int)path.size());
    		return;
    	}
    	for(int i = 0; i < wordList.size(); i++) {
    		if(!visited[i] && oneDifference(beginWord, wordList[i])) {
    			visited[i] = true;
    			path.emplace_back(wordList[i]);
    			helper(wordList[i], endWord, wordList, path, visited, ret, min_level);
    			path.pop_back();
    			visited[i] = false;
    		}
    	}
    }

    bool oneDifference( string s1, string s2) {
    	int ret = 0;
    	for(int i = 0; i < s1.size(); i++) {
    		if(s1[i] != s2[i]) {
    			ret++;
    			if(ret > 1) {
    				return false;
    			}
    		}
    	}
    	return ret == 1;
    }
};


