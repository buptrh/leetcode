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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        list<vector<int>> nodes;
        vector<vector<int>> res;
        if(root == NULL) {
        	return res;
        }
        list<vector<int>>::iterator it = nodes.begin();
        helper(root, nodes, it);
		copy(nodes.begin(),nodes.end(),back_inserter(res));
        return res;
    }

    void helper(TreeNode* root, list<vector<int>> & nodes, list<vector<int>>::iterator it) {
    	if(root == NULL) {
    		return;
    	}
    	if(it == nodes.end()) {
    		// cout<< "create" << root->val<<endl;
    		nodes.insert(it, vector<int>());
    		it--;
    	}
    	it->push_back(root->val);
    	// cout<<root->val << " : "; output(nodes, it);
    	if(root->left != NULL && it == nodes.begin()) {
    		nodes.insert(it, vector<int>());
    	}
    	helper(root->left, nodes, prev(it));
    	// cout<<"right. " << root->val << " : "; output(nodes, it);
    	helper(root->right, nodes, next(it));
    	// cout<<"after. " << root->val << " : "; output(nodes, it);
    }

    void output(list<vector<int>> & nodes, list<vector<int>>::iterator & it) {
    	// if(it != nodes.end()) {
    	// 	vector<int> temp = *it;
    	// 	for(int i : temp) {
    	// 		cout<<i << "  ";
    	// 	}
    	// }
    	for(vector<int> vec : nodes) {
    		cout<<"[ ";
	    	for(int i : vec) {
    			cout<<i << "  ";
    		}
    		cout<<" ], ";
    	}
		cout<<endl;
    }
};