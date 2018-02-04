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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while(!que.empty()) {
        	int size = que.size();
        	vector<int> level;
        	for(int i = 0; i < size; i++) {
        		TreeNode* node = que.front();
        		que.pop();
        		if(node == NULL) {
        			continue;
        		}
        		level.push_back(node->val);
        		que.push(node->left);
        		que.push(node->right);
        	}
        	if(level.size() > 0) {
        		res.push_back(level);
        	}
        }
        reverse(res.begin(), res.end());
        return res;
    }
};