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
    int largestBSTSubtree(TreeNode* root) {
        int maxV = 0, minV = 0, res = 0;
        isBST(root, maxV, minV, res);
        return res;
    }

    bool isBST(TreeNode* root, int & maxV, int & minV, int & res) {
    	if(root == NULL) {
    		maxV = INT_MIN;
    		minV = INT_MAX;
    		res = 0;
    		return true;
    	}
    	int lmax = INT_MIN, lmin = INT_MAX, lcount = 0, rmax = INT_MIN, rmin = INT_MAX, rcount = 0;
    	maxV = root->val;
    	minV = root->val;
    	bool isLeft = false, isRight = false;
    	isLeft = isBST(root->left, lmax, lmin, lcount);
    	isRight = isBST(root->right, rmax, rmin, rcount);
    	if(isLeft && isRight) {
    		if(root->val > lmax && root->val < rmin) {
    			if(root->left != NULL){
    				minV = lmin;
    			}
    			if(root->right != NULL){
    				maxV = rmin;
    			}
    			res = max(res, lcount + rcount + 1);
    			// cout<<root->val << " " << minV << " " << maxV<<" " << res << endl;
    			return true;
    		} 
    	}
		res = max(lcount, rcount);
    	

    	return false;
    }
};