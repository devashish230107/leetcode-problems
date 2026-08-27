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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int n = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            n++;
        }
        if (k >= n) {
            k = k % n;
        }
        if (k == 0)
            return head;
        temp->next = head;
        int traverse = n - k - 1;
        temp = head;
        while (traverse != 0) {
            temp = temp->next;
            traverse--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};