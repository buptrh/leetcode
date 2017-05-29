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
    bool isValidBST(TreeNode* root) {
    	if(root == NULL) {
    		return true;
    	}
    	return isValid(root, INT_MIN, INT_MAX, false, false);
     }

    bool isValid(TreeNode * root, int minVal, int maxVal, bool checkMin, bool checkMax) {
   		if(root == NULL) {
    		return true;
    	}
    	// cout<<"isValid" << root->val << "|" << minVal<< "  " << maxVal<< "  " << checkMin<< "  " <<checkMax << endl;
        if(root->left != NULL ) {
        	if(checkMax && root->left->val >= maxVal) {
        		return false;
        	}

    		if(checkMin && root->left->val <= minVal ) {
    			return false;
    		}

        	if(root->left->val >= root->val) {
        		return false;
        	}
        }
        if(root->right != NULL ) {
        	if(checkMax && root->right->val >= maxVal) {
        		return false;
        	}

    		if(checkMin && root->right->val <= minVal ) {
    			return false;
    		}
    		
            if(root->right->val <= root->val) {
        		return false;
        	}
        }
        int newMax = maxVal, newMin = minVal;
        bool newCheckMax = checkMax, newCheckMin = checkMin;
        if(root->val <= maxVal) {
        	newMax = root->val;
        	newCheckMax = true;
        }
        if(root->val >= minVal) {
        	newMin = root->val;
        	newCheckMin = true;
        }
        return isValid(root->left, minVal, newMax, checkMin, newCheckMax) 
        	&& isValid(root->right, newMin, maxVal, newCheckMin, checkMax);
    }
};


//binary search tree follow the ascending order if traversal the tree in DFS

