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
    ListNode *detectCycle(ListNode *head) {
        
    	if(head == NULL) {
    		return NULL;
    	}
        ListNode* fast = head, *slow = head;
        bool init = true;
        while(fast != slow || init) {
        	if(fast == NULL || fast->next == NULL) {
        		return NULL;
        	}
        	init = false;
        	fast = fast->next->next;
        	slow = slow->next;
        }
	    slow = head;
	    while( slow != fast) {
	        slow = slow->next;
	        fast = fast->next;
	    }
	    return slow;
    }
};