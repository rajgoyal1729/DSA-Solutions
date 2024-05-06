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
    ListNode* reverse(ListNode* head1)
    {
        ListNode* curr=head1;
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp1=head;
        head=reverse(temp1);
        int maxim=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            maxim=max(maxim,curr->val);

            if(curr->val<maxim)
            {prev->next=curr->next;
            ListNode* del=curr;
            curr=curr->next;
            del->next=NULL;}
            
            else{
            prev=curr;
            curr=curr->next;
            }
        }
        return reverse(head);
    }
};