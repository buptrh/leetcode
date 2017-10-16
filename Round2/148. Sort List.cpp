/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if(head == NULL || head->next == NULL) {
    		return head;
    	}
        ListNode* fast = head->next, *slow = head;
        while(fast != NULL && fast->next != NULL) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        ListNode* left = sortList(slow->next);
        slow->next = NULL;
        ListNode* right = sortList(head);
        ListNode dummy(0), *node = &dummy;
        while(left != NULL || right != NULL) {
        	if(left != NULL && right != NULL){
        		if(left->val < right->val) {
	        		node->next = left;
	        		left = left->next;
	        	} else {
	        		node->next = right;
	        		right = right->next;
	        	}
	        } else {
	        	if(left == NULL) {
	        		node->next = right;
	        		right = right->next;
	        	} else if(right == NULL) {
	        		node->next = left;
	        		left = left->next;
	        	}
	        }
        	node = node->next;
        }
        return dummy.next;
    }
};