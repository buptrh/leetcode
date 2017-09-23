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
        if(l1 == NULL && l2 == NULL ) {
        	return NULL;
        }
        if(l1 == NULL) {
        	return addTwoNumbers(l2, l1);
        }
        int add = 0;
        ListNode * ret = l1, *prev = l1;
        while(l1 != NULL) {
        	int sum = l1->val + add;
        	if(l2 != NULL) {
        		sum += l2->val;
        	}
        	l1->val = sum % 10;
        	add = sum / 10;
        	prev = l1;
        	l1 = l1->next;
        	
        	if(l2 != NULL) {
        		l2 = l2->next;
        	}
        	if(l1 == NULL) {
        		prev->next = l2;
        		l1 = prev->next;
        		l2 = NULL;
        	}
        }
        if(add != 0) {
        	prev->next = new ListNode(add);
        }
        return ret;
    }
};