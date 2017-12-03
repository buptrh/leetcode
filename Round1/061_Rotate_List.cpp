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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode * node = head, *end = NULL;
        while( node != NULL ){
        	length ++;
        	end = node;
        	node = node->next;
        }
        if(k > length && length != 0) {
        	k = k%length;
        }
        if(k == length || length == 0 || k == 0) {
        	return head;
        }
        int index = 0;
        node = head;
        while(index < length - k - 1) {
        	node = node->next;
        	index++;
        }
        ListNode * temp = node->next;
        end->next = head;
        node->next = NULL;
        return temp;
    }
};