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
	map<int, pair<int, int>> distMap;
	pair<int, int> res;
    int findClosestLeaf(TreeNode* root, int k) {
    	dfs(root);
    	dfs2(root, make_pair(INT_MAX, 0), k);
    	return res.second;
    }

    pair<int, int> dfs(TreeNode* root) {
    	if(root == NULL) {
    		return make_pair(INT_MAX, 0);
    	}
    	if(root->left == NULL && root->right == NULL) {
    		distMap[root->val] = make_pair(1, root->val);
    		return distMap[root->val];
    	}
       	pair<int, int> l = dfs(root->left);
    	pair<int, int> r = dfs(root->right);
    	if(l.first < r.first) {
    		distMap[root->val] = l;
    	} else {
    		distMap[root->val] = r;
    	}
    	distMap[root->val].first = distMap[root->val].first + 1;
    	// cout<<root->val<<". " << distMap[root->val].first << "  " << distMap[root->val].second<<endl;
    	return distMap[root->val];
    }

    void dfs2(TreeNode* root, pair<int, int> dist, int k) {
    	if(root == NULL) {
    		return;
    	}
    	if(dist.first > distMap[root->val].first) {
    		dist = distMap[root->val];
    	}
    	if(root->val == k) {
    		res = dist;
    		return;
    	}
    	dist.first += 1;
    	dfs2(root->left, dist, k);
    	dfs2(root->right, dist, k);
    	return;
    }
};