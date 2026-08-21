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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        int count=n-1;
        ListNode* temp=head;
        ListNode* temp2=temp;
        ListNode* back=nullptr;
        while(temp!=nullptr){
            while(count>0){
                temp2=temp2->next;
                count--;
            }
            if(temp2->next==nullptr){
                break;
            }
            count=n-1;
            back=temp;
            temp=temp->next;
            temp2=temp;
        }
        if(back==nullptr) return head->next;
        back->next=temp->next;
        temp->next=nullptr;
        return head;
    }
};