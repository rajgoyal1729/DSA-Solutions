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
        // two pass solution
        /*if(head->next==NULL) return NULL;
       ListNode* temp=head;
       int length=0;
       while(temp!=NULL)
       {
           length++;
           temp=temp->next;
       }
       if(length==n) return head->next;
       ListNode* temp1=head;
       int k=0;
       while(temp1!=NULL)
       {
           k++;
           if(k==(length-n))
           {
               temp1->next=temp1->next->next;
               break;
           }
           temp1=temp1->next;

       }
       return head;
    }*/
    //one pass solution;
    ListNode* slow=head;
    ListNode* fast=head;
    for(int i=0;i<n;i++) fast=fast->next;
    if(fast==NULL) return head->next;
    while(fast->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
    }
};