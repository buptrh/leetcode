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
    ListNode* oddEvenList(ListNode* head) {
    	if(head == NULL) {
    		return head;
    	}
        ListNode* odd = head, *even = head->next, *headEven = even, *node = even;
        while(node != NULL) {
        	odd->next = node->next;
        	node = node->next;
        	if(node == NULL) {
        		break;
        	}
        	odd = odd->next;
        	node = node->next;
        	even->next = node;
        	even = even->next;
        }
        odd->next = headEven;
        return head;
    }
};