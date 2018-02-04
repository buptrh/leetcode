/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode*> sta;
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
        	sta.push(root);
        	root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
    	if(sta.empty()) {
    		return -1;
    	}
        TreeNode* node = sta.top();
        sta.pop();
        int res = node->val;
        node = node->right;
        while(node != NULL) {
        	sta.push(node);
        	node = node->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */