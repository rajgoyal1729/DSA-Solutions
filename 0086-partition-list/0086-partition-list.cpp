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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                ListNode* node = new ListNode(temp->val);
                curr->next = node;
                curr = curr->next;
            }
            temp = temp->next;
        }
        ListNode* temp1 = head;
        while (temp1) {
            if (temp1->val >= x) {
                ListNode* node = new ListNode(temp1->val);
                curr->next = node;
                curr = curr->next;
            }
            temp1 = temp1->next;
        }
        return ans->next;
    }
};