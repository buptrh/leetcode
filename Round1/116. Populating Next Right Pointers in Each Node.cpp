/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {

    	TreeLinkNode * node = root, *cur, *pre;
        
        while(node != NULL) {
        	cur = node;
        	pre = NULL;
        	while(node != NULL && node->left != NULL) {
        		if(pre != NULL) {
        			pre->right->next = node->left;
        		}
        		node->left->next = node->right;
        		// cout<<node->left->val << "  next:" << node->right->val<<endl;
        		pre = node;
        		node = node->next;
        	}
        	node = cur->left;
        }
    }
};