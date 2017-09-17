class MagicDictionary {
public:
	set<string> table;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0; i < dict.size(); i++) {
        	table.insert(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto it = table.begin(); it != table.end(); it++) {
        	int flag = 0;
        	if(word.size() != (*it).size()) {
        		continue;
        	}
        	for(int i = 0; i < word.size(); i++) {
        		if(word[i] != (*it)[i]) {
        			flag++;
        			if(flag > 1) {
        				break;
        			}
        		}
        	}
        	// cout<<*it<<". "<< flag << endl;
        	if(flag == 1) {
        		return true;
        	}
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */