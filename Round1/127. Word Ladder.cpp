class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dup;
        for(string word : wordList) {
        	dup.insert(word);
        }
        if(dup.find(endWord) == dup.end()) {
        	return 0;
        }
        queue<string> bfsQueue;
        bfsQueue.push(beginWord);
        int count = 0;
        while(!bfsQueue.empty()) {
        	int size = bfsQueue.size();
        	for(int i = 0; i < size; i++) {
        		string s = bfsQueue.front();
        		bfsQueue.pop();
        		for(int m = 0; m < s.size(); m++) {
	        		for(int j = 0; j < 26; j++) {
	        			string temp = s;
	        			temp[m] = 'a'+j;
	        			if(temp == endWord) {
	        				return count+2;
	        			}
	        			if(dup.find(temp) != dup.end()) {
	        				bfsQueue.push(temp);
	        				dup.erase(temp);
	        			}
	        		}
        		}
        	}
        	count++;
        }
        return 0;
    }
};