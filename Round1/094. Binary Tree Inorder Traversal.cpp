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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
    	if(root == NULL) {
    		return ret;
    	}
        stack<TreeNode*> sta;
        TreeNode* node = root;
        sta.push(node);
    	while(node->left != NULL) {
    		sta.push(node->left);
    		node = node->left;
    	}
        while(sta.size() != 0) {
        	node = sta.top();
        	ret.emplace_back(node->val);
        	// cout<<node->val<<endl;
    		sta.pop();
    		if(node->right != NULL) {
    			node = node->right;
    			sta.push(node);
		    	while(node->left != NULL) {
		    		sta.push(node->left);
		    		node = node->left;
		    	}
    		}
        }
        return ret;
    }
};