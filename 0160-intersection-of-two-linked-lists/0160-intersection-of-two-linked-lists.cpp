/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int count1=0,count2=0;//intersection
        ListNode *head1=headA;
        ListNode *head2=headB;

        while(head1)
        {
            count1++;
            head1=head1->next;
        } 

        while(head2)
        {
            count2++;
            head2=head2->next;
        } 

        while(count1>count2)
        {
            count1--;
            headA= headA->next;
        }

        while(count2>count1)
        {
            count2--;
            headB= headB->next;
        }

        while(headA && headB)
        {
            if(headA==headB)
            return headA;

            headA=headA->next;
            headB=headB->next;
        }


        return NULL;
    }
};