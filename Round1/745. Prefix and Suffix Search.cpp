class WordFilter {
public:
	class FixNode {
	public:
		FixNode(char _c) {
			c = _c;
		}
		unordered_map<char, FixNode *> next;
		unordered_map<string, int> wordsMap;
		char c;
	};
    FixNode * prefixList;
    FixNode * suffixList;
    WordFilter(vector<string> words) {
    	prefixList = new FixNode(0);
    	suffixList = new FixNode(0);
        for(int i = 0; i < words.size(); i++) {
            cout<<words[i]<<endl;
        	string word = words[i];
        	FixNode * p = prefixList;
        	prefixList->wordsMap[word] = i;
        	for(char c : word) {
        		if(p->next.find(c) == p->next.end()) {
        			p->next[c] = new FixNode(c);
        		} 
    			p->next[c]->wordsMap[word] = i;
        		p = p->next[c];
        	}

        	FixNode * s = suffixList;
        	suffixList->wordsMap[word] = i;
        	for(int j = word.size()-1; j >= 0; j--) {
        		char c = word[j];
        		if(s->next.find(c) == s->next.end()) {
        			s->next[c] = new FixNode(c);
        		}
    			s->next[c]->wordsMap[word] = i;
        		s = s->next[c];
        	}
        }
    }
    
    int f(string prefix, string suffix) {
        int res = -1;
        unordered_map<string, int> test;
        unordered_map<string, int>* preMap = &(prefixList->wordsMap);
        unordered_map<string, int>* sufMap = &(suffixList->wordsMap);
    	FixNode * p = prefixList;
    	FixNode * s = suffixList;
    	for(char c : prefix) {
    		if(p->next.find(c) == p->next.end()) {
    			preMap = &test;
    			break;
    		} else {
    			preMap = &p->next[c]->wordsMap;
    		}
    		p = p->next[c];
    	}

        for(int j = suffix.size()-1; j >= 0; j--) {
            char c = suffix[j];
    		if(s->next.find(c) == s->next.end()) {
    			sufMap = &test;
    			break;
    		} else {
    			sufMap = &s->next[c]->wordsMap;
    		}
    		s = s->next[c];
    	}

    	for(auto it : *preMap) {
    		if(sufMap->find(it.first) != sufMap->end()) {
    			res = max(it.second, res);
    		}
    	}
    	return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */