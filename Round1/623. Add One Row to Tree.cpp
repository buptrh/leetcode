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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	TreeNode dummy(0);
    	dummy.left = root;
    	solve(&dummy, d, v);
    	return dummy.left;

    }

    void solve(TreeNode * root, int level, int v) {
    	if(root == NULL) {
    		return;
    	}
    	// cout<<root->val<<". " << level <<endl;
    	if(level == 1) {
    			TreeNode * node = new TreeNode(v);
    			node->left = root->left;
    			root->left = node;

    			TreeNode * node2 = new TreeNode(v);
    			node2 ->right = root->right;
    			root->right = node2;
    	} else if(level > 1){
    		solve(root->left, level-1, v);
    		solve(root->right, level-1, v);
    	}
    }
};