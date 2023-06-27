// My version
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <list>
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* hh = new ListNode(0, head);
		ListNode* nprev = hh;

		for (int i = 1; i != n; ++i)
			head = head->next;

		while (head->next != nullptr) {
			head = head->next;
			nprev = nprev->next;
		}

		ListNode* delNode = nprev->next;
		nprev->next = nprev->next->next;
		delete delNode;

		return hh->next;
	}
};
