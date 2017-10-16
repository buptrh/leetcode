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
        map<RandomListNode*, RandomListNode*> table;
        RandomListNode* node = head, *dummy = new RandomListNode(0), *prev = dummy;
        while(node != NULL) {
        	RandomListNode* newnode = new RandomListNode(node->label);
        	prev->next = newnode;
        	table[node] = newnode;
        	prev = newnode;
        	node = node->next;
        }

        node = head;
        while(node != NULL) {
        	table[node]->random = table[node->random];
        	node = node->next;
        }
        return dummy->next;
    }
};