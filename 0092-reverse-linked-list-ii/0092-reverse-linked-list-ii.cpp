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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int l=1,r=1,count=1;
        ListNode* startEle=head;
        ListNode* prevEle=head;
        ListNode* lastEle=head;
        while(l<left)
        {
            prevEle=startEle;
            startEle=startEle->next;
            l++;
        }
        while(r<=right)
        {
            lastEle=lastEle->next;
            r++;
        }
        ListNode* curr=startEle;
        ListNode* next;
        ListNode* prev=NULL;
        while(count<=right-left+1)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(startEle==prevEle) head=prev;
        else prevEle->next= prev;
        startEle->next=curr;
        return head;
    }
};