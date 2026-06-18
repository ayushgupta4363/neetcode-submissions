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
        
        ListNode*head1=l1;
        ListNode*head2=l2;
        ListNode*dummy=new ListNode(0);

        ListNode*curr=dummy;
        int carry=0;
        while(head1!=NULL || head2!=NULL|| carry!=0){

        int val1=(head1!=NULL)? head1->val:0;
        int val2=(head2!=NULL)? head2->val:0;
        int value = val1 + val2 + carry;

        carry=value/10;
        int num=value%10;
        ListNode*temp=new ListNode(num);
        curr->next=temp;
        curr=temp;

        if(head1){head1=head1->next;}
        if(head2){head2=head2->next;}
        
         }
     return dummy->next;
    } 
};
