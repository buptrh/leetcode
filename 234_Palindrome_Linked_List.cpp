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
    bool isPalindrome(ListNode* head) {
    	ListNode * front = head;
    	ListNode * back = NULL;
        while(front != NULL) {
        	back = reverseList(front->next);
        	if(back != NULL && front->val != back->val) {
        		return false;
        	}
        	if(back == NULL) {
        		break;
        	}
        	front = back->next;
        }
        return true;
    }

    ListNode * reverseList(ListNode * head) {
    	if(head == NULL ) {
    		return NULL;
    	}
    	ListNode * pre = head;
    	ListNode * next = pre->next;
    	pre->next = NULL;
    	ListNode * temp = NULL;
    	while(next != NULL) {
    		temp = next->next;
    		next->next = pre;
    		pre = next;
    		next = temp;
    	}
    	return pre;
    }
};

// my previous solution is o(n^2)

// new solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL) {
    		return true;
    	}
    	ListNode * firstHalf = head;
    	ListNode * secondHalf = head;
    	while(secondHalf->next != NULL && secondHalf->next->next != NULL) {
    		firstHalf = firstHalf->next;
    		secondHalf = secondHalf->next->next;
    	}
    	firstHalf = reverseList(firstHalf);
    	secondHalf = head;
        while(firstHalf != NULL && secondHalf != NULL) {
        	if(firstHalf -> val != secondHalf -> val) {
        		return false;
        	}
        	firstHalf = firstHalf->next;
        	secondHalf = secondHalf->next;
        }
        return true;
    }

    ListNode * reverseList(ListNode * head) {
    	if(head == NULL ) {
    		return NULL;
    	}
    	ListNode * pre = head;
    	ListNode * next = pre->next;
    	pre->next = NULL;
    	ListNode * temp = NULL;
    	while(next != NULL) {
    		temp = next->next;
    		next->next = pre;
    		pre = next;
    		next = temp;
    	}
    	return pre;
    }
};
