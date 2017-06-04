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
    	ListNode * node = head, *next = NULL, *prev = NULL;
        while(node != NULL) {
        	next = node->next;
        	node->next = prev;
        	prev = node;
        	node = next;
        }

        return prev;
    }
};