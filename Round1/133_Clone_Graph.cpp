/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL) {
    		return NULL;
    	}
        map<UndirectedGraphNode*, UndirectedGraphNode*> duplicate;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
		duplicate[node] = root;
        cloneNode(node, root, duplicate);
        return root;
    }

    void cloneNode(UndirectedGraphNode * from, UndirectedGraphNode* to,  map<UndirectedGraphNode*, UndirectedGraphNode*> & duplicate) {
    	to->neighbors.clear();
    	for(int i = 0; i < from->neighbors.size(); i++) {
    		if(duplicate[from->neighbors[i]] != NULL ) {
    			to->neighbors.emplace_back(duplicate[from->neighbors[i]]);
    			continue;
    		}
    		UndirectedGraphNode* node = new UndirectedGraphNode(from->neighbors[i]->label);
    		duplicate[from->neighbors[i]] = node;
    		to->neighbors.emplace_back(node);
    		cloneNode(from->neighbors[i], node, duplicate);
    	}
    }
};