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
    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL) {
    		return true;
    	}
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        if(fast != NULL) {
        	slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        while(slow != NULL && fast != NULL && slow->val == fast->val) {
        	slow = slow->next;
        	fast = fast->next;
        }
        if(slow != NULL) {
        	return false;
        }
        return true;
    }

    ListNode* reverse(ListNode* head ) {
    	ListNode * node = head, *prev = NULL, *next;
    	while(node != NULL) {
    		next = node->next;
    		node->next = prev;
    		prev = node;
    		node = next;
    	}
    	return prev;
    }
};