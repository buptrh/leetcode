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
        int maxOne = 0, maxVal = INT_MIN;
        dfs(root, maxOne, maxVal);
        return maxVal;
    }

    void dfs(TreeNode* root, int & maxOne, int & maxVal) {
    	if(root == NULL) {
    		maxOne = 0;
    		return;
    	}
    	int maxL = INT_MIN, maxR = INT_MIN;
    	dfs(root->left, maxL, maxVal);
    	dfs(root->right, maxR, maxVal);
    	int val = root->val;
    	if(maxL > 0) {
    		val += maxL;
    	}
    	if(maxR > 0) {
    		val += maxR;
    	}
    	maxOne = max(max(maxL, maxR), 0) + root->val;
    	maxVal = max(maxVal, val);
    }
};