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
	int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
        	return 0;
        }
        treeLength(root);
        return maxDiameter;
    }

    int treeLength(TreeNode* node) {
    	if(node == NULL) {
    		return 0;
    	}
    	int l = treeLength(node->left);
    	int r = treeLength(node->right);
    	maxDiameter = max(maxDiameter, l+r);
    	return max(l, r) + 1;
    }
};