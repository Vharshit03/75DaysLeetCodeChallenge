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
        
        ListNode *ans=new ListNode;
        ListNode *temp = ans;
        int carry=0,sum; // sum 2->1->- 0 = 012

        while(l1 && l2)
        {
            int num1 = l1->val;
            int num2 = l2->val;

            sum = num1+num2+carry;

            int num = sum%10;
            carry = sum/10;

            ListNode*sum = new ListNode(num);
            
            temp->next = sum;
            temp = temp->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            int num1 = l1->val;
            sum = num1 +carry;
            int num = sum%10;
            carry = sum/10;

            ListNode*sum = new ListNode(num);
            
            temp->next = sum;
            temp = temp->next;

            l1 = l1->next;
        }

        while(l2)
        {
            int num1 = l2->val;
            sum = num1 +carry;
            int num = sum%10;
            carry = sum/10;

            ListNode*sum = new ListNode(num);
            
            temp->next = sum;
            temp = temp->next;
            
            l2 = l2->next;
        }

        if(carry)
        {
            ListNode*sum = new ListNode(carry);
            
            temp->next = sum;
        }

        return ans->next;
    }
};