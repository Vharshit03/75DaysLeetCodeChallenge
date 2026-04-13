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
        ListNode* ptr = head,*temp = head;

        while(n--)
        ptr = ptr->next;

        if(!ptr) return head->next;

        while(ptr->next){
            temp = temp->next;
            ptr = ptr->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};