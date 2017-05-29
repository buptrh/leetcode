/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        	if(root == NULL) {
        		return;
        	}
        int row = 0, count = 1,currentCount = 0, nextCount = 0;
        queue<TreeLinkNode* > nodes;
        nodes.emplace(root);
        TreeLinkNode * preNode;
        while(nodes.size() != 0) {
        	TreeLinkNode * node = nodes.front();
        	nodes.pop();
        	currentCount++;
        	
        	if(preNode != NULL) {
        		preNode->next = node;
        	}

        	if(node->left != NULL){
        		nodes.emplace(node->left);
        		nextCount++;
        	}
        	
        	if(node->right != NULL){
        		nodes.emplace(node->right);
        		nextCount++;
        	}
        	
        	if(currentCount == count) {
        		node->next = NULL;
        		currentCount = 0;
        		count = nextCount;
        		nextCount = 0;
        		preNode = NULL;
        	}  else {
        		preNode = node;
        	}
        }
    }
};