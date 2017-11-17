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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, int pS, int pE, vector<int>& inorder, int iS, int iE) {
    	if(pS > pE || iS > iE || pS >= preorder.size() || pE >= preorder.size() || iS >= inorder.size() || iE >= inorder.size()) {
    		return NULL;
    	}
        int v = preorder[pS], m = 0;
        for(int i = iS; i <= iE; i++) {
        	if(inorder[i] == v) {
        		m = i - iS;
        	}
        }
        TreeNode * node = new TreeNode(v);
        TreeNode * left = helper(preorder, pS +1, pS + m, inorder, iS, iS + m-1);
        TreeNode * right = helper(preorder, pS + m + 1, pE, inorder, iS + m+1, iE);
        node->left = left;
        node->right = right;
        return node;
    }
};