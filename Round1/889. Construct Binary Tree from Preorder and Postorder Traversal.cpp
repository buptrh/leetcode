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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    	return help(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }


    TreeNode* help(vector<int>& pre, int fromPre, int endPre, vector<int>& post, int fromPost, int endPost) {
        if(pre[fromPre] != post[endPost] || fromPre > endPre || fromPost > endPost || endPre - fromPre != endPost - fromPost) {
        	return NULL;
        }
        TreeNode * root = new TreeNode(pre[fromPre]);
        unordered_set<int> values;
        for(int i = 0; i < endPre - fromPre; i++) {
        	if(values.count(pre[fromPre + i + 1])) {
        		values.erase(pre[fromPre + i + 1]);
        	} else {
        		values.insert(pre[fromPre + i+1]);
        	}
        	if(values.count(post[fromPost + i])) {
        		values.erase(post[fromPost + i]);
        	} else {
        		values.insert(post[fromPost + i]);
        	}
        	if(values.size() == 0) {
        		root->left = help(pre, fromPre+1, fromPre+i + 1, post, fromPost, fromPost + i);
        		root->right = help(pre, fromPre+i+2, endPre, post, fromPost+i+1, endPost - 1);
        		return root;
        	}
        }
        return root;
    }
};