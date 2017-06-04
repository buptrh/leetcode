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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode * ret = head;
    	if(head == NULL || head->next == NULL) {
    		return head;
    	}
    	ListNode * beforeHead = NULL, *current = NULL, *next = NULL, *prev = NULL;
        while(head != NULL && m > 1) {
        	beforeHead = head;
        	head = head->next;
        	m--;
        	n--;
        }
        current = head;

        while(current != NULL && n > 0) {
        	next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
        	n--;
        }
    	head->next = current;
        if(beforeHead != NULL) {
        	beforeHead->next = prev;
        } else {
        	ret = prev;
        }

        return ret;
    }
};