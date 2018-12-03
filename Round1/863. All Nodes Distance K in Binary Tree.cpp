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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
    	if(root == NULL) {
    		return res;
    	}
        unordered_set<int> path;
        unordered_map<int, int> depth;
        dfs(root, target, path, depth);
        // cout << "depth" << depth[root->val]<<endl;
        // for(int i : path) {
        // 	cout<<i<<"  ";
        // }
        // cout<<endl;
        bfs(root, target, path, depth[root->val] - K + 1, res);
        return res;
    }

    bool dfs(TreeNode* root, TreeNode* target, unordered_set<int> & path, unordered_map<int, int> & depth) {
    	if(root == NULL) {
    		return false;
    	}
    	if(root == target) {
    		path.insert(root->val);
    		depth[root->val] = 0;;
    		return true;
    	}
    	if(dfs(root->left, target, path, depth)) {
    		path.insert(root->val);
    		depth[root->val] = depth[root->left->val]+1;
    		return true;
    	}
    	if(dfs(root->right, target, path, depth)) {
    		path.insert(root->val);
    		depth[root->val] = depth[root->right->val]+1;
    		return true;
    	}
    	return false;
    }

    void bfs(TreeNode* root, TreeNode* target, unordered_set<int> & path, int K, vector<int>& res) {
    	if(root == NULL) {
    		return;
    	}
    	if(path.count(root->val) > 0) {
    		K--;
    	} else {
    		K++;
    	}
    	if(K == 0) {
    		res.push_back(root->val);
    	}
    	// cout<< "bfs: " << root->val << "  " << K << endl;
    	bfs(root->left, target, path, K, res);
    	bfs(root->right, target, path, K, res);

    }


};