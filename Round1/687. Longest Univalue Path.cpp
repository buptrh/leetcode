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
    int longestUnivaluePath(TreeNode* root) {
    	if(root == NULL) {
    		return 0;
    	}
    	int len = 0, ret = 0;
    	
    	helper(root, len, ret);
    	if(ret >= 2) {
    		ret --;
    	} else {
    		ret = 0;
    	}
        return ret;
    }

    void helper(TreeNode* root, int & len, int & ret) {
    	if(root == NULL) {
    		return;
    	}
    	int l = 1, r = 1;
    	if(root->left != NULL) {
    		ret = max(ret, l);
    		helper(root->left, l, ret);
	    	if(root->left->val == root->val) {
	    		ret = max(ret, l+1);
	    		len = max(len, l+1);
	    	}
    	}

    	if(root->right != NULL) {
    		helper(root->right, r, ret);
    		ret = max(ret, r);

	    	if(root->right->val == root->val) {
	    		ret = max(ret, r+1);
	    		len = max(len, r+1);
		    	if(root->left != NULL && root->left->val == root->right->val) {
		    		ret = max(ret, l+r+1);
		    		// cout<<"!!!" << l+r+1<<endl;
		    	}
	    	}
    	}

    }
};