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
    string tree2str(TreeNode* t) {
        string ret;
        if(t == NULL) {
        	return "";
        }
    	ret += to_string(t->val);

        if(t->left != NULL) {
        	ret += "(" + tree2str(t->left) + ")"; 
        	if(t->right != NULL) {
        		ret += "(" + tree2str(t->right) + ")";
        	}
        } else {
        	if(t->right != NULL) {
        		ret += "()(" + tree2str(t->right) + ")";
        	}
        }
        return ret;
    }
};