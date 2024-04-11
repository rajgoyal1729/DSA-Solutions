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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans= new ListNode(0);
        ListNode* curr=ans;
        int sum=0;
        int value=0;
        int carry=0;
        while(l1 || l2)
        {
            sum= carry+(l1?l1->val:0)+ (l2?l2->val:0);
            
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            curr->next=temp;
            curr=curr->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

        }
        if(carry)
        {
            ListNode* node=new ListNode(carry);
            curr->next=node;
        }
        return ans->next;
    }
};