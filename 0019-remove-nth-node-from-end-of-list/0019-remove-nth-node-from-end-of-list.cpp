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
        ListNode* temp = head;
        int sz = 0;

        while(temp){
            sz++;
            temp = temp->next;
        }

        sz = sz-n-1;

        if(sz<0)
        return head->next;
        
        temp = head;
        while(sz--){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};