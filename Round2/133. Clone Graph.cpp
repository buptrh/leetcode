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
        map<UndirectedGraphNode*, UndirectedGraphNode* > table;
        vector<UndirectedGraphNode*> nodeList;
        nodeList.push_back(node);
    	UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
    	table[node] = newNode;	
        int index = 0;
        while(index < nodeList.size()) {
        	for(UndirectedGraphNode* neighbor : nodeList[index]->neighbors) {
        		if(table.find(neighbor) == table.end()) {
		        	UndirectedGraphNode * newNode = new UndirectedGraphNode(neighbor->label);
		        	table[neighbor] = newNode;
        			nodeList.push_back(neighbor);
        		}
        		table[nodeList[index]]->neighbors.push_back(table[neighbor]);
        	}
        	index++;
        }

        return table[node];
    }
};