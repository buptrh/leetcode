/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        while(!nodes.empty()) {
        	vector<TreeNode*> newNodes;
        	for(int i = 0; i < nodes.size(); i++) {
        		if(nodes[i] == NULL && nodes[nodes.size()-1-i] == NULL) {

        		} else if(nodes[i] == NULL || nodes[nodes.size()-1-i] == NULL) {
        			return false;
        		} else if(nodes[i]->val != nodes[nodes.size()-1-i]->val) {
        			return false;
        		} else {
        			newNodes.push_back(nodes[i]->left);
        			newNodes.push_back(nodes[i]->right);
        		}
        	}
        	nodes = newNodes;
        }
        return true;
    }
};