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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(n == 0 || head == NULL) {
    		return head;
    	}
        ListNode* node = head, *left = head;
        while(n >= 0 && node != NULL) {
        	node = node->next;
        	n--;
        }
        if(n == 0 && node == NULL) {
        	return head->next;
        } else if(n > 0) {
        	return head;
        }
        while(node != NULL) {
        	node = node->next;
        	left = left->next;
        }
        ListNode * temp = left->next->next;
        left->next = temp;
        return head;
    }
};