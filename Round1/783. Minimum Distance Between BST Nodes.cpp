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
	int res = INT_MAX;
	unordered_set<int> values;
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return res;
    }

    void helper(TreeNode* root) {
    	if(root == NULL) {
    		return;
    	}
    	for(int i : values) {
    		res = min(res, abs(i - root->val));
    	}
    	values.insert(root->val);
    	if(res == 0) {
    		return;
    	}
    	helper(root->left);
    	helper(root->right);
    }
};