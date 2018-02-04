class AutocompleteSystem {
public:
	class TrieNode {
	public:
		TrieNode() {
			wordCount = 0;
		}
		int wordCount;
		string prefix;
		map<char, TrieNode*> next;
		map<string, TrieNode*> leaves;
	private:
	};

	TrieNode* insert(string s, int times, int index, TrieNode* node) {
		if(index == s.size()) {
			node->wordCount += times;
			node->leaves[s] = node;
			return node;
		}
		char c = s[index];
		// cout<< "insert: " << s << "  " <<index <<  endl;
		if(node->next[c] == NULL) {
			node->next[c] = new TrieNode();
			node->next[c]->prefix = node->prefix + c;
		}
		TrieNode* leaf = insert(s, times, index+1, node->next[c]);
		node->leaves[s] = leaf;
		return leaf;

	}
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
    	root = new TrieNode();
    	currNode = root;
        for(int i = 0; i < sentences.size(); i++) {
        	insert(sentences[i], times[i], 0, root);
        }
        // cout<<"finish constractor" << endl;
    }
    
    vector<string> input(char c) {
    	// cout<<"input: " << c << endl;
    	vector<string> res;
        if(c != '#') {
        	if(currNode->next[c] == NULL) {
        		currNode->next[c] = new TrieNode();
        		currNode->next[c]->prefix = currNode->prefix + c;
        	}
    		currNode = currNode->next[c];

	    	auto comp = [](TrieNode* a, TrieNode* b) {
		    	if(a->wordCount == b->wordCount) {
		    		return a->prefix < b->prefix;
		    	} else {
		    		return a->wordCount > b->wordCount;
		    	}
			};
			priority_queue<TrieNode*, vector<TrieNode*>, decltype(comp)> que(comp);
			for(auto n : currNode->leaves) {
				que.push(n.second);
				if(que.size() > 3) {
					que.pop();
				}
			}
			while(!que.empty()) {
				res.push_back(que.top()->prefix);
				que.pop();
			}
			reverse(res.begin(), res.end());
    	} else {
        	// cout<<currNode->prefix<<endl;
        	insert(currNode->prefix, 1, 0, root);
        	currNode = root;
        }
        return res;
    }

    TrieNode* root;
    TrieNode* currNode;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */