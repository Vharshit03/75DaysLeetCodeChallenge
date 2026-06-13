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
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0 || head==NULL )
        return head;
        
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            n += 1;
            temp = temp->next;
        }

        if(n==1 || k==n || k%n==0)
        return head;

        k = k%n;
        k = n - k;

        temp = head;

        while(--k){
            temp = temp->next;
        }

        ListNode* newhead = temp->next;
        ListNode* temp2 = temp->next;
        temp->next = NULL;

        while( temp2!=NULL && temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = head;

        return newhead;
    }
};