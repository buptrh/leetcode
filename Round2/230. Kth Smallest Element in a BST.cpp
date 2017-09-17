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
    	if(root == NULL) {
    		return -1;
    	}
        int count = countNodes(root->left);
        if(k <= count) {
        	return kthSmallest(root->left, k);
        } else if (k > count + 1) {
        	return kthSmallest(root->right, k - count - 1);
        } else {
        	return root->val;
        }
    }

    int countNodes(TreeNode * root) {
    	if(root == NULL) {
    		return 0;
    	}
    	return 1 + countNodes(root->left) + countNodes(root->right);
    }
};