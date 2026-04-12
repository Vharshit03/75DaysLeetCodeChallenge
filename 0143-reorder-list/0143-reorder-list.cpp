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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while(second){
            slow = second->next;
            second->next = prev;
            prev = second;
            second = slow;
        }

        second = prev;
        ListNode* first = head;


        while(second){
            slow = first->next;
            fast = second->next;
            first->next = second;
            second->next = slow;
            first =slow;
            second = fast;
        }


    }
};