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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res(2, NULL);
        if(root == NULL) {
        	return res;
        }
        bool flag = false;
        if(root->val < V) {
        	res[0] = root;
        	helperSmall(root, res, V);
        } else {
        	res[1] = root;
        	helperBig(root, res, V);
        }

        return res;
    }

    void helperBig(TreeNode* root, vector<TreeNode*>& res, int V) {
    	if(root->left == NULL) {
    		return;
    	}
    	if(root->left->val <= V) {
    		res[0] = root->left;
    		TreeNode* temp = root->left;
    		root->left = root->left->right;
    		temp->right = NULL;
    	} else {
    		helperBig(root->left, res, V);
    	}
    }

    void helperSmall(TreeNode* root, vector<TreeNode*>& res, int V) {
    	if(root->right == NULL) {
    		return;
    	}
    	if(root->right->val > V) {
    		res[1] = root->right;
    		TreeNode* temp = root->right;
    		root->right = root->right->left;
    		temp->left = NULL;
    	} else {
    		helperSmall(root->right, res, V);
    	}
    }
};