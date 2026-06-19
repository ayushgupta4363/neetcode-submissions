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
    ListNode*merge(ListNode*list1,ListNode*list2){

    if(list1->next==NULL){
      list1->next=list2;
      return list1;}

     ListNode*curr1=list1;
     ListNode*curr2=list2;
     ListNode*forward2=NULL;
     ListNode*forward1=NULL;

    while(curr1->next!=NULL && curr2!=NULL){

    if(curr1->val<=curr2->val && curr2->val <= curr1->next->val){
        curr1->next=curr2;
        forward2 =curr2->next;
        forward1=curr1->next;
        curr2->next=forward1;
        curr1=curr2;
        curr2=forward2;
     }
     
    else{
        curr1=forward1;
        forward1=forward1->next;
        if(forward1->next==NULL){
            curr1->next=curr2;
            return curr1;
        }

     }
    }
     return curr1;

    }

    ListNode* mergeTwoLists(ListNode*list1,ListNode*list2){
     if(list1==NULL){return list2;}
     if(list2==NULL){return list1;}
     if(list1->val > list2->val){
        swap(list1,list2);
        }
     ListNode*curr1=list1;
     ListNode*curr2=list2;
     ListNode*forward2=NULL;
     ListNode*forward1=NULL;

    while(curr1->next!=NULL && curr2!=NULL){

    if(curr1->val<=curr2->val && curr2->val <= curr1->next->val){
        forward2=curr2->next;
        forward1=curr1->next;

        curr1->next=curr2;
        curr2->next=forward1;

        curr1=curr2;
        curr2=forward2;
     }
     
    else{
        curr1=curr1->next;
     }
    }
     if(curr2!=NULL){
        curr1->next=curr2;
     }

      return list1;
         }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        if(lists.empty()){return NULL;}
        int k =lists.size();

        for(int i=1;i<k;i++){
         lists[i] = mergeTwoLists(lists[i-1],lists[i]);  
        }
        return lists[k-1];
    }
};
