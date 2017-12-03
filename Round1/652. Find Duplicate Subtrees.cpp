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
	map<string, pair<TreeNode*, bool> > table;
	vector<TreeNode*> se;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    	if(root == NULL) {
    		return se;
    	}
        traverseTree(root);

	    return se;
    }

    string traverseTree(TreeNode * root) {
    	string ret = to_string(root->val) + "/" ;
    	if(root->left == NULL) {
    		ret += "N";
    	} else {
    		ret += traverseTree(root->left);
    	}
    	ret += "_";
    	if(root->right == NULL) {
    		ret += "N";
    	} else {
    		ret += traverseTree(root->right);
    	}
    	if(table.find(ret) != table.end()) {
    		// cout<<ret << endl;
    		if(table[ret].second) {
    			se.push_back(root);
    			// se.push_back(table[ret].first);
    			table[ret].second = false;
    		}
    	} else {
    		// cout<<ret << endl;
    		table[ret] = pair<TreeNode*, bool> (root, true);;
    		// cout<< ret << "  " << root->val << endl;
    	}
    	return ret;
    }
};