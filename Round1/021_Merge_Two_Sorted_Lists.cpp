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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0), *node = head;
        while(l1 != NULL && l2 != NULL) {
        	if(l1->val <= l2->val) {
        		node->next = l1;
        		l1 = l1->next;
        	} else {
        		node->next = l2;
        		l2 = l2->next;
        	}
            node = node->next;
        }

        if(l1 != NULL) {
        	node->next = l1;
        } else {
        	node->next = l2;
        }
        return head->next;

    }
};