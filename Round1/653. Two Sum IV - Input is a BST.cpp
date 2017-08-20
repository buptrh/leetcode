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
    bool findTarget(TreeNode* root, int k) {
    	bool ret = false;
    	TreeNode* node = root;
    	stack<TreeNode*> sta;
    	sta.push(node);
        while(sta.size() > 0) {
        	node = sta.top();
        	sta.pop();
    		ret = helper(root, k - node->val, node);

    		if(ret) {
    			return true;
    		}
        	if(node->left != NULL) {
        		sta.push(node->left);
        	}

        	if(node->right != NULL) {
        		sta.push(node->right);
        	}

        }
        return false;
    }

    bool helper(TreeNode* root, int v, TreeNode* no) {
    	// cout<<"find:" << v << endl; 
    	TreeNode* node = root;
    	while(node != NULL) {
    		// cout<<"search:"<<node->val << endl;
    		if(node->val < v) {
    			node = node->right;
    		} else if(node->val > v) {
    			node = node->left;
    		} else if(node == no){
    			break;
    		} else {
    			return true;
    		}
    	}
    	return false;
    }
};