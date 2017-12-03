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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if(t1 == NULL && t2 == NULL) {
    		return NULL;
    	}
		TreeNode * node = new TreeNode(0);
    	solve(t1, t2, node);
    	return node;
    }

    void solve(TreeNode * t1, TreeNode * t2, TreeNode * parent) {
    	parent->val += (t1 != NULL ? t1->val : 0); 
    	parent->val += (t2 != NULL ? t2->val : 0); 
    	TreeNode * t1left = NULL, * t2left = NULL, *t1right = NULL, *t2right = NULL;
    	if (t1 != NULL) {
    		t1left = t1->left;
    		t1right = t1->right;
    	}
    	if (t2 != NULL) {
    		t2left = t2->left;
    		t2right = t2->right;
    	}
    	if(t1left != NULL || t2left != NULL)  {
    		TreeNode * node = new TreeNode(0);
    		parent->left = node;
        	solve(t1left, t2left, node);
    	}
    	if(t1right != NULL || t2right != NULL)  {
    		TreeNode * node = new TreeNode(0);
    		parent->right = node;
        	solve(t1right, t2right, node);
    	}
    }
};