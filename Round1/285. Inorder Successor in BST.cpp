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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode * node = root, *res = NULL;
        while(node != NULL) {
        	if(node->val > p->val) {
        		res = node;
        		node = node->left;
        	} else {
        		node = node->right;
        	}
        }
        return res;
    }
};