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
    ListNode* insertionSortList(ListNode* head) {
    	if(head == NULL || head->next == NULL) {
    		return head;
    	}
        ListNode dummy(0);
        dummy.next = head;
        ListNode* x = head->next, *y = &dummy, *temp = NULL;
       	head->next = NULL;
        while(x != NULL) {
        	while( y->next != NULL && x->val > y->next->val) {
        		y = y->next;
        	}
        	temp = x->next;
        	x->next = y->next;
        	y->next = x;
        	x = temp;
        	y = &dummy;
        }
        return dummy.next;
    }
};