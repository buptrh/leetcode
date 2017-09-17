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
	int sum ;
    int sumNumbers(TreeNode* root) {
        sum = 0;
        helper(root);
        return sum;
    }

    void helper(TreeNode * node) {
    	if(node == NULL) {
    		return;
    	}
    	if(node->left != NULL) {
    		node->left->val = node->val * 10 + node->left->val;
    		helper(node->left);
    	}
    	if(node->right != NULL) {
    		node->right->val = node->val * 10 + node->right->val;
    		helper(node->right);
    	}
    	if(node->left == NULL && node->right == NULL) {
    		sum += node->val;
    	}
    }
};