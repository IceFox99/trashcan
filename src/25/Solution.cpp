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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *root = new ListNode(0, head);
        ListNode *beg = root, *curr = head;
        int num = 0;

        while (curr) {
            ListNode* next = curr->next;
            ++num;
            if (num == k) {
                cout << beg->val << endl;
                ListNode* new_beg = beg->next;
                ListNode* end = next;
                while (num-- != 1) {
                    ListNode* top = beg->next;
                    beg->next = top->next;
                    top->next = end;
                    end = top;
                }
                beg->next->next = end;
                beg = new_beg;
                num = 0;
            }

            curr = next;
        }

        ListNode* res = root->next;
        delete root;
        return res;
    }
};
