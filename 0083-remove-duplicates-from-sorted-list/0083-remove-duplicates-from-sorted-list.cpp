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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2;

        if(!head)
        return head;

        while(temp->next){
            temp2 = temp->next;

            if(temp->val == temp2->val)
            temp->next = temp2->next;
            else
            temp = temp2;
        }

        return head;
    }
};