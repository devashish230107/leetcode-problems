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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return {-1,-1};
        int pos=2;
        ListNode* temp=head->next;
        ListNode* prev=head;
        int mindis=INT_MAX;
        int maxdis=-1;
        int firstpos=-1;
        int nowpos=-1;
        int prevpos=-1;
        while(temp->next!=nullptr){
            if((prev->val<temp->val && temp->val>temp->next->val)||(prev->val>temp->val && temp->val<temp->next->val)){
                prevpos=nowpos;
                nowpos=pos;
                if(prevpos!=-1){
                    mindis=min(mindis,nowpos-prevpos);
                }
                else{
                    firstpos=nowpos;
                }
            }
            pos++;
            temp=temp->next;
            prev=prev->next;
        }
        if(mindis==INT_MAX) return {-1,-1};
        maxdis=nowpos-firstpos;
        return {mindis,maxdis};
    }
};