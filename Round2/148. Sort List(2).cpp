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
        ListNode* fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;

    	fast = sortList(fast);
        slow = sortList(slow);
        // cout<<slow->val << "  " << fast->val<<endl;
        return mergeList(fast, slow);
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
    	ListNode dummy(-1);
    	ListNode * node = &dummy;
    	while(l1 != NULL && l2 != NULL) {
    		if(l1->val < l2->val) {
    			node->next = l1;
    			node = l1;
    			l1 = l1->next;
    		} else {
    			node->next = l2;
    			node = l2;
    			l2 = l2->next;
    		}
    	}
    	if(l1 != NULL) {
    		node->next = l1;
    	} else {
    		node->next = l2;
    	}
    	return dummy.next;
    }

};