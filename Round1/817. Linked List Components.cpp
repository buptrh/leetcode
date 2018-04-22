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
    int numComponents(ListNode* head, vector<int>& G) {
    	if(head == NULL){
    		return 0;
    	}
    	if(head->next == NULL) {
    		return 1;
    	}
        unordered_map<int, int> nextTable;
        unordered_map<int, int> prevTable;
        ListNode* temp = head->next, *prev = head;
        while(temp != NULL) {
        	prevTable[temp->val] = prev->val;
        	nextTable[prev->val] = temp->val;
        	// cout<<"insert:  " << prev->val << "  " << temp->val <<endl;
        	prev = temp;
        	temp = temp->next;
        }

        unordered_set<int> values;
        unordered_set<int> visited;

        for(int i : G) {
        	values.insert(i);
        }
        int ret = 0;
        for(int i : G) {
        	if(visited.count(i) == 0) {
        		dfs(G, values, visited, nextTable, prevTable, i) ;
        		ret++;
        		// cout<< i << endl;
        	}
        }
        return ret;
    }

    void dfs(vector<int>& G, unordered_set<int> & values, unordered_set<int> & visited, unordered_map<int, int>& nextTable, unordered_map<int, int> &prevTable, int i) {
    	if(visited.count(i) > 0) {
    		return;
    	}
		visited.insert(i);
    	if(nextTable.find(i) != nextTable.end() && values.count(nextTable[i]) > 0) {
    		dfs(G, values, visited, nextTable, prevTable, nextTable[i]);
    	}
    	if(prevTable.find(i) != prevTable.end() && values.count(prevTable[i]) > 0) {
    		dfs(G, values, visited, nextTable, prevTable, prevTable[i]);
    	}
    	return;
    }
};