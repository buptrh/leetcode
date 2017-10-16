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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL) {
    		l1 = l2;
    		l2 = NULL;
    	}
    	if(l1 == NULL) {
    		return NULL;
    	}
        int add = 0;
        ListNode dummy(0);
        dummy.next = l1;
        ListNode *prev = &dummy;
        while(l1 != NULL && l2 != NULL) {
        	l1->val = l1->val + l2->val + add;
        	add = l1->val / 10;
        	l1->val = l1->val % 10;
        	prev = l1;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        if(l1 == NULL) {
        	prev->next = l2;
        	l1 = prev->next;
        }
        while(add > 0) {
        	if(prev->next == NULL) {
        		prev->next = new ListNode(add);
        		add = 0;
        	} else {
        		prev->next->val += add;
        		add = prev->next->val / 10;
        		prev->next->val = prev->next->val % 10;
        		prev = prev->next;
        	}
        }
        return dummy.next;
    }
};