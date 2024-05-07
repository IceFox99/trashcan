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
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *root = head, *curr = head->next, *last = head;
        if (head->val > 4)
            root = new ListNode(1, head);
        head->val = head->val * 2 % 10;

        while (curr) {
            if (curr->val > 4)
                ++last->val;
            curr->val = curr->val * 2 % 10;

            last = curr;
            curr = curr->next;
        }

        return root;
    }
};
