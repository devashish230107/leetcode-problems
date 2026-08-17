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
    bool samenextexist(ListNode* temp, int count) {
        while (count>0) {
            temp = temp->next;
            if (temp == nullptr) {
                return false;
            }
            count--;
        }
        return true;
    }
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;
        int count = 1;
        ListNode* temp = head;
        while (true) {
            if(!samenextexist(temp,count)){
                return temp;
            }
            temp=temp->next;
            count++;
        }
    }
};