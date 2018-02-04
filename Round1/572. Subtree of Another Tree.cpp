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
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	if(t == NULL) {
    		return true;
    	} else if( s == NULL) {
        	return false;
        }
        if(s->val == t->val) {
        	if(isSameTree(s, t)) {
        		return true;
        	}
        }
        if(isSubtree(s->left, t) || isSubtree(s->right, t)) {
        	return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* s, TreeNode* t) {
    	if(t == NULL && s == NULL) {
    		return true;
    	} else if(t == NULL || s == NULL) {
        	return false;
        }
        if(s->val != t->val) {
        	return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};