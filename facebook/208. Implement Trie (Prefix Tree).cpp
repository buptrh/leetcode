class Trie {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> table;
        bool isWord;
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->table[c] == NULL) {
                node->table[c] = new TrieNode();
            }
            node = node->table[c];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode* node = root;
        for(char c : word) {
            if(node->table[c] == NULL) {
                return false;
            }
            node = node->table[c];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* node = root;
        for(char c : prefix) {
            if(node->table[c] == NULL) {
                return false;
            }
            node = node->table[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */