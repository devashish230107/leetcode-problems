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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* front = nullptr;
        ListNode* back = nullptr;
        while (temp != nullptr) {
            front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }
        return back;
    }
    ListNode* kthnodefn(ListNode* head, int k) {
        k -= 1;
        ListNode* temp = head;
        while (temp != nullptr && k != 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = nullptr;
        while (temp != nullptr) {
            ListNode* kthnode = kthnodefn(temp, k);
            if (kthnode == nullptr) {
                if (prevlast != nullptr)
                    prevlast->next = temp;
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = nullptr;
            reverseList(temp);
            if (temp == head) {
                head = kthnode;
            } else {
                prevlast->next = kthnode;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};