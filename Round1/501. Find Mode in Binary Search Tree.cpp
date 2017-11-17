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
    vector<int> findMode(TreeNode* root) {
        int val = INT_MIN;
        int maxCount = 0, count = 0;
        vector<int> ret;
        helper(root, maxCount, val, count, ret);

        return ret;
    }

    void helper(TreeNode* node, int & maxCount, int & val, int & count, vector<int>& rets) {
    	if(node == NULL) {
    		return;
    	}
    	if(node->left != NULL) {
    		helper(node->left, maxCount, val, count, rets);
    	}
    	if(val == node->val) {
    		count++;
    	} else {
    		count = 1;
    		val = node->val;
    	}
    	if(count > maxCount) {
    		maxCount = count;
    		rets.clear();
    		rets.push_back(val);
    	} else if(count == maxCount) {
    		rets.push_back(val);
    	}

    	if(node->right != NULL) {
    		helper(node->right, maxCount, val, count, rets);
    	}
    }

};