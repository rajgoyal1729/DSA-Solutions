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
    ListNode* reverse(ListNode* node)
    {
        ListNode* curr=node;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* node=reverse(head);
        ListNode* temp=node;
        ListNode* answer= new ListNode();
        ListNode* ans=answer;
        int carry=0;
        while(temp)
        {
            int x=2*(temp->val)+carry;
            int digit=x%10;
            ListNode* curr= new ListNode(digit);
            ans->next=curr;
            ans=ans->next;
             carry= x/10;
            temp=temp->next;
        }
        if(carry!=0) ans->next= new ListNode(carry);
        return reverse(answer->next);
    }
};