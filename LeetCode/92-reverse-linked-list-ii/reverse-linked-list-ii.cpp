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
    ListNode*reverse(ListNode*head,int left,int right){
        ListNode*front;
        ListNode*prev=NULL;
        ListNode*temp=head;
        while(temp!=NULL&&left<=right){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
            left++;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode*temp=head;
        int c=1;
        while(temp!=NULL&&c<left-1){
            temp=temp->next;
            c+=1;
        }
        ListNode*prev;
        if(left==1){
            prev=NULL;
        }
        else{
            prev=temp;
        }
        while(temp!=NULL&&c!=right){
            temp=temp->next;
            c+=1;
        }
        ListNode*after=NULL;
        if(temp->next!=NULL){
            after=temp->next;
        }
        if(prev!=NULL){
            prev->next=reverse(prev->next,left,right);
            temp=prev->next;
        }
        else{
            head=reverse(head,left,right);
            temp=head;
        }

        while(temp!=NULL&&temp->next!=NULL){
            temp=temp->next;
        }
        if(temp==NULL)return head;
        temp->next=after;
        return head;
  
    }
};