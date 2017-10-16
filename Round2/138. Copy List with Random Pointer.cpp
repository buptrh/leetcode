/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL) {
    		return head;
    	}
    	RandomListNode * node = head, *ret;
        while(node != NULL) {
        	RandomListNode * n = new RandomListNode(node->label);
        	n->next = node->next;
        	node->next = n;
        	node = n->next;
        }
        node = head;
        while(node != NULL) {
        	if(node->random != NULL){
        		node->next->random = node->random->next;
        	}
        	node = node->next->next;
        }
        node = head;
        ret = node->next;
    	RandomListNode * n = node->next;
        while(node != NULL) {
    		n = node->next;
    		node->next = n->next;
        	node = n->next;
        	if(n->next != NULL) {
        		n->next = n->next->next;
        	}
        }
        return ret;
    }
};