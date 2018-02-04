class Solution {
public:
	struct TrieNode {
        unordered_map<char, vector<pair<int, int>>> table;
    };
    
    void insert(TrieNode* node, vector<vector<char>>& board, pair<int, int> pos) {
    	if(pos.first < 0 || pos.second < 0 || pos.first >= board.size() || pos.second >= board[0].size()) {
    		return;
    	}
    	if(nodesMap[pos] == NULL) {
    		nodesMap[pos] = new TrieNode();
    	}
    	node->table[board[pos.first][pos.second]].push_back(pos);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        set<pair<int, int>> visited;
        if(dfsSearch(prefix, 0, visited, root)) {
        	return true;
        }
        return false;
    }
    bool dfsSearch(string prefix, int start, set<pair<int, int>>& visited, TrieNode* node) {
    	if(canFind.find(prefix.substr(start)) != canFind.end()) {
    		return true;
    	}
    	if(cantFind.find(prefix.substr(start)) != cantFind.end()) {
    		return false;
    	}
    	if(start >= prefix.size()) {
    		return true;
    	}
    	char c = prefix[start];
        for(int j = 0; j < node->table[c].size(); j++) {
        	if(visited.find(node->table[c][j]) != visited.end()) {
        		continue;
        	}
    		visited.insert(node->table[c][j]);
    		if(dfsSearch(prefix, start+1, visited, nodesMap[node->table[c][j]])) {
    			canFind.insert(prefix.substr(start));
    			return true;
    		}
    		visited.erase(node->table[c][j]);
        }
        cantFind.insert(prefix.substr(start));
        return false;
    }

    TrieNode* root;
    map<pair<int, int>, TrieNode*> nodesMap;
    unordered_set<string> canFind;
    unordered_set<string> cantFind;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < board.size(); i++) {
        	for(int j = 0; j < board[0].size(); j++) {
        		pair<int, int> pos = make_pair(i, j);
        		insert(root, board, pos);
        		insert(nodesMap[pos], board, make_pair(i+1, j));
        		insert(nodesMap[pos], board, make_pair(i-1, j));
        		insert(nodesMap[pos], board, make_pair(i, j+1));
        		insert(nodesMap[pos], board, make_pair(i, j-1));
        	}
        }

        unordered_set<string> resset;
        for(string s : words) {
        	if(startsWith(s)) {
        		resset.insert(s);
        	}
        }
        vector<string> res;
        copy(resset.begin(), resset.end(), back_inserter(res));
        return res;
    }
};