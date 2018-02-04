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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode * prev = &dummy;
        dummy.next = head;
        int count = k;
        ListNode * left = head, *right = left;
        while(true) {
	        while(count > 1 && right != NULL) {
	        	right = right->next;
	        }
	        if(count == 1 && right != NULL) {
	        	prev->next = right;
	        	left->next = right->next;
	        	ListNode* node = left;
	        	while(node != right) {
	        		ListNode * temp = node->next;
	        		node->next->next = node;
	        		node = temp;
	        	}
	        } else {
	        	break;
	        }
        }

        return dummy.next;
    }
};