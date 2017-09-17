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
    int kthSmallest(TreeNode* root, int k) {
    	TreeNode * node = solve(root, k);
    	if(node != NULL) {
    		return node->val;
    	} else {
    		return -1;
    	}
    }
    TreeNode * solve(TreeNode* root, int& k) {
    	if(root == NULL) {
    		return NULL;
    	}
        TreeNode* node = solve(root->left, k);
        if(node != NULL) {
        	return node;
        }
        k--;
        if(k == 0) {
        	return root;
        }
        node = solve(root->right, k);
        return node;
    }
};