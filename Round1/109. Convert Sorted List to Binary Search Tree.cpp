/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
    	if(head == NULL) {
    		return NULL;
    	}
    	ListNode* fast = head, *slow = head, *pre = NULL;
    	while(fast != NULL && fast->next != NULL) {
    		fast = fast->next->next;
    		pre = slow;
    		slow = slow->next;
    	}
    	TreeNode* node = new TreeNode(slow->val);
    	if(slow != fast) {
			node->right = sortedListToBST(slow->next);
	    	if(pre != NULL) {
	    		pre->next = NULL;
	    	}
	    	node->left = sortedListToBST(head);
    	}
    	return node;
    }
};