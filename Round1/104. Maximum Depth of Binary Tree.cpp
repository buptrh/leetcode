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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root) {
    	if(root == NULL) {
    		return 0;
    	}
    	if(root->left == NULL && root->right == NULL) {
    		return 1;
    	}
    	return max(dfs(root->left), dfs(root->right)) + 1;
    }
};