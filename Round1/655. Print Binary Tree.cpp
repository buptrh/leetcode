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
    vector<vector<string>> printTree(TreeNode* root) {
        int col = 0, row = 0;
        helper(root, 0, 1, col, row);
        for(int i = 0; i < row; i++) {
        	if(i == 0) {
        		col = 1;
        	} else {
        		col *= 2;
        		col ++;
        	}
        }
        // cout<<col << "  " << row;
        vector<vector<string>> ret(row, vector<string>(col, ""));
        fill(root, ret, col, 0, 0);
        return ret;
    }

    void helper(TreeNode* root, int col, int row, int & maxCol, int & maxRow) {
    	maxCol = max(maxCol, abs(col));
    	maxRow = max(maxRow, row);
    	if(root->left != 0) {
    		helper(root->left, col-1, row+1, maxCol, maxRow);
    	}

    	if(root->right != 0) {
    		helper(root->right, col+1, row+1, maxCol, maxRow);
    	}
    }

    void fill(TreeNode* root ,vector<vector<string>> & ret, int col, int row, int colOffset) {
    	if(root != NULL) {
    		// cout<<row<<". " << colOffset + col/2 << "  " << root->val << endl;
    		ret[row][colOffset + col/2] = to_string(root->val);
    		fill(root->left, ret, (col-1)/2, row+1, colOffset);
    		fill(root->right, ret, (col-1)/2, row+1, colOffset + col/2+1);
    	}
    }
};