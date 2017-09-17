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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head) { // partition
    	ListNode * fast = head, *slow = head;
    	if(head == NULL) {
    		return NULL;
    	}
    	while(fast->next != NULL && fast->next->next != NULL) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	ListNode* l1, *l2;
    	if(fast == head) {
    		l2 = head->next;
    		head->next = NULL;
    		l1 = head;
    	} else {
    		l2 = mergeSort(slow->next);
    		slow->next = NULL;
    		l1 = mergeSort(head);
    	}
    	// cout<<"1" <<endl;
    	ListNode dummy(0);
    	ListNode * ret = &dummy;
    	while(l1 != NULL && l2 != NULL) {
    		//cout<<"!!"<<l1->val << "  " << l2->val <<endl;
    		if(l1->val <= l2->val) {
    			ret->next = l1;
    			l1 = l1->next;
    		} else {
    			ret->next = l2;
    			l2 = l2->next;
    		}
    		ret = ret ->next;
    	}
    	ret->next = l1 == NULL ? l2 : l1;
    	//cout<<"2" <<endl;
    	return dummy.next;
    }

    ListNode* bubbleSort(ListNode* head) {
    	if(head == NULL) {
    		return head;
    	}
    	ListNode dummy = ListNode(0);
    	dummy.next = head;
    	ListNode* end = NULL, *current = head, *point = current, *pre = &dummy, *small = NULL, *prePoint = pre, *preSmall = NULL;
    	while(current != NULL) {
	    	while(point != NULL) {
	    		if(small == NULL) {
	    			small = point;
	    			preSmall = prePoint;
	    		} else if(small->val > point->val) {
	    			small = point;
	    			preSmall = prePoint;
	    		}
	    		prePoint = point;
	    		point = point->next;
	    	}
	    	// cout<<small->val<<endl;
	    	if(small != current) {
		    	pre->next = small;
		    	preSmall->next = small->next;
		    	small->next = current;

		    	pre = small;
		    	// current = current->next;
	    	} else {
		    	pre = small;
	    		current = current->next;
	    	}
	    	// cout<<"end" << current->val <<endl;
	    	point = current;
	    	// while( point != NULL) {
	    	// 	cout<<point->val<<". ";
	    	// 	point = point->next;
	    	// }
	    	// cout<<endl;
	    	point = current;
	    	prePoint = pre;
	    	preSmall = pre;
	    	small = current;
    	}
    	return dummy.next;
    }
    ListNode *bubbleSort2( ListNode *L )
	{
	ListNode *p= NULL, *tail = NULL, *next= NULL;
	int temp = 0;
		if( L->next->next == NULL )
			return L;
		for( p = L->next; p->next != NULL; p = p->next )    
			;
		tail = p;
		while( tail != L->next->next )
		{
			for( p = L->next; p->next != tail; p = p->next )
			{
				next = p->next;
				if( p->val > next->val )   
				{
					temp = p->val;
					p->val = next->val;
					next->val = temp;
				}
			}
			tail = p;    
		}
		return L;
	}
};