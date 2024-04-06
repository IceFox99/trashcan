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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* l, ListNode* r) {
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (int i = 0; i != lists.size(); ++i) {
            if (lists[i])
                pq.push(lists[i]);   
        }

        ListNode* root = new ListNode();
        ListNode* iter = root;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if (temp->next)
                pq.push(temp->next);
            iter->next = temp;
            iter = iter->next;
        }
        iter = root->next;
        delete root;
        return iter;
    }
};

// Community version, divide and conquer
class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};
