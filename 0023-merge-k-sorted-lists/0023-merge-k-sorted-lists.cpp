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
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (a && b) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if (a)
            temp->next = a;
        else
            temp->next = b;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        int n = lists.size();

        while (n > 1) {
            int j = 0;

            for (int i = 0; i < n; i += 2) {
                if (i + 1 < n)
                    lists[j++] = mergeTwo(lists[i], lists[i + 1]);
                else
                    lists[j++] = lists[i];
            }

            n = j;
        }

        return lists[0];
    }
};