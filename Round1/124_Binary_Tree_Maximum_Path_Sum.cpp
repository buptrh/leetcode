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
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        traversalTree(root, maxVal);
        return maxVal;
    }
    int traversalTree(TreeNode * node, int & maxVal) {
    	if(node == NULL) {
    		return 0;
    	}
    	int leftVal = traversalTree(node->left, maxVal);
    	int rightVal = traversalTree(node->right, maxVal);
    	maxVal = max(maxVal, leftVal + rightVal + node->val);
    	node->val = max(leftVal, rightVal) + node->val;
    	if(node->val < 0) {
    		node->val = 0;
    	}
    	return node->val;
    }
};