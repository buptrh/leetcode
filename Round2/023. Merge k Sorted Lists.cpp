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
    	auto comp = [](ListNode* a, ListNode* b) {
		    return a->val > b->val;
		};

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> listPriority(comp);
        for(int i = 0; i < lists.size(); i++) {
        	if(lists[i] != NULL){
        		listPriority.push(lists[i]);
        	}
        }
        ListNode dummy(0);
        ListNode * node = &dummy;
        while(!listPriority.empty()) {
        	node->next = listPriority.top();
        	listPriority.pop();
        	if(node->next->next != NULL){
        		listPriority.push(node->next->next);
        	}
        	node = node->next;
        }

        return dummy.next;
    }
};