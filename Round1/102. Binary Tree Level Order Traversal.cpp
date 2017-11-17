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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
        	int size = nodes.size();
        	vector<int> line;
        	for(int i = 0; i < size; i++) {
	        	TreeNode* node = nodes.front();
	        	nodes.pop();
	        	if(node != NULL) {
	        		line.push_back(node->val);
	        		nodes.push(node->left);
	        		nodes.push(node->right);
	        	}
        	}
        	if(line.size() > 0){
        		ret.push_back(line);
        	}
        }
        return ret;
    }
};