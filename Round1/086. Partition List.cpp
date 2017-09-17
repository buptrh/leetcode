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
    ListNode* partition(ListNode* head, int x) {
    	ListNode dummy(x-1);
    	dummy.next = head;
        ListNode* left = &dummy, *right = head, *rightPrev = &dummy;
        while(right != NULL) {
        	if(right->val < x) {
        		if(left->next == right) {
        			left = left->next;
        			rightPrev = right;
        			right = right->next;
        		} else {
	        		ListNode* temp = left->next;
	        		rightPrev->next = right->next;
	        		left->next = right;
	        		right->next = temp;
	        		left = right;
	        		right = rightPrev->next;
        		}
        	} else {
        		rightPrev = right;
        		right = right->next;
        	}
        }

        return dummy.next;
    }
};