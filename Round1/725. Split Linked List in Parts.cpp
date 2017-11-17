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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret(k, root);
        if(root == NULL) {
        	return ret;
        }

        int total = 0;
        ListNode* node = root;
        while(node != NULL) {
        	node = node->next;
        	total++;
        }
        vector<int> sums(k, 0);
        for(int i = 0; i < k; i++) {
        	sums[i] = total/k;
        	if(total % k > 0) {
        		sums[i]++;
        		total --;
        	}
        	// cout<<sums[i] << endl;
        }

        int index = sums[0];
        ListNode* prev = NULL;
        for(int i = 1; i < k; i++) {
        	for(int j = 0; j < index; j++) {
        		ret[i] = ret[i]->next;
        	}
        	index += sums[i];
        }
        node = root;
        index = 1;
        while(node != NULL) {
        	// cout<<node->val<<endl;
         	if( node ->next == ret[index]) {
        		ListNode* temp = node->next;
        		node->next = NULL;
        		node = temp;
        		index++;
        	} else {
        		node = node->next;
        	}
        }
        return ret;
    }
};