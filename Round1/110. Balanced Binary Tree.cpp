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
    bool isBalanced(TreeNode* root) {
    	int val = 0;
        return dfs(root, val);
    }

    bool dfs(TreeNode* root, int & val) {
    	if(root == NULL) {
    		val = 0;
    		return true;
    	}
    	int lval = 0, rval = 0;
    	if(!dfs(root->left, lval) || !dfs(root->right, rval)) {
    		return false;
    	}
    	if(abs(lval - rval) > 1) {
    		return false;
    	}
    	val = max(lval, rval) + 1;
    	return true;
    }
};