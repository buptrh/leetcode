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
	int maxVal = 0;
    int longestConsecutive(TreeNode* root) {
    	helper(root);
    	return maxVal;
    }

    int helper(TreeNode* root) {
        if(root == NULL) {
        	return 0;
        }
        int res = 1;
        if(root->left != NULL) {
        	int l = helper(root->left);
        	if(root->val == root->left->val - 1) {
        		res = max(res, l+1);
        		// cout<<"left: " << res << endl;
        	}
        }
        if(root->right != NULL) {
        	int r = helper(root->right);
        	if(root->val == root->right->val - 1) {
        		res = max(res, r+1);
        		// cout<<"right: " << res << "  " << root->right->val << " " << r <<  endl;
        	}
        }
        // cout<<root->val << "  " << res << endl;
    	maxVal = max(maxVal, res);
    	return res;
    }
};