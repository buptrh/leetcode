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
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL) {
    		return NULL;
    	}
        ListNode* next = head->next, *prev = NULL;
        while(head != NULL) {
        	next = head->next;
        	head->next = prev;
        	prev = head;
        	head = next;
        }
        return prev;
    }
};