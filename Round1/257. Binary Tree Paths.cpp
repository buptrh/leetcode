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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root == NULL) {
        	return ret;
        }
        ret.emplace_back(to_string(root->val));
        helper(ret, root, 0);
        return ret;
    }

    void helper(vector<string> & ret, TreeNode* root, int index) {
    	// cout<< to_string(root->val) << endl;

    	if(root->right != NULL) {
    		if(root->left == NULL) {
    			ret[index] = ret[index] + "->" + to_string(root->right->val);
    			helper(ret, root->right, index);
    		} else {
    			ret.emplace_back(ret[index] + "->" + to_string(root->right->val));
    			helper(ret, root->right, ret.size()-1);
    		}
    	}

    	if(root->left != NULL) {
    		ret[index] = ret[index] + string("->") + to_string(root->left->val);
    		helper(ret, root->left, index);
    	}
    }
};