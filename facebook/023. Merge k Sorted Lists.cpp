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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	auto comp = [](ListNode* n1, ListNode* n2) {
    		return n1->val > n2->val;
    	};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(ListNode* l : lists) {
        	if(l != NULL) {
        		pq.push(l);
        	}
        }
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(!pq.empty()) {
        	node->next = pq.top();
        	pq.pop();
        	node = node->next;
        	if(node->next != NULL) {
        		pq.push(node->next);
        	}
        }
        return dummy.next;
    }
};