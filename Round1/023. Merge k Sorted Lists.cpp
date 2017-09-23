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
    	if(lists.size() == 0) {
    		return NULL;
    	}
       
		auto comp = [](ListNode* a, ListNode* b) {
		    return a->val > b->val;
		};
		priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> queue(comp);

		for(int i = 0; i < lists.size(); i++) {
			if(lists[i] != NULL) {
				queue.emplace(lists[i]);
			}
		}
		ListNode * ret = new ListNode(-1), * node = ret;
		while(!queue.empty()) {
			node->next = queue.top();
			queue.pop();
			node = node->next;
			if(node->next != NULL) {
				queue.emplace(node->next);
			}
		}
		return ret->next;
    }
};