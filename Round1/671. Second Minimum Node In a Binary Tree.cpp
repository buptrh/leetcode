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
    int findSecondMinimumValue(TreeNode* root) {
        int ret = -1, mini = root->val;
        queue<TreeNode*> que;
        que.emplace(root);
        while(que.size() != NULL) {
        	TreeNode* node = que.front();
        	que.pop();
        	
    		if(node->val < mini) {
    			mini = node->val;
    			ret = mini;
    		} else if((ret < 0 || ret > node->val) && node->val != mini) {
    			// cout<<ret<<"  " << node->val<<endl;
    			ret = node->val;
    		}
    		if(node->left != NULL) {
        		que.emplace(node->left);
        		que.emplace(node->right);
        	}
        }
        return ret;
    }


};