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
class compare{
    public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }

};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //make pq
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        //makinga answer ll
        ListNode* head=NULL;
        ListNode* tail=NULL;

        //processing first node of very node
        int totalrow=lists.size();
        for(int row=0;row<totalrow;row++){
            ListNode* temp=lists[row];
            if(temp!=NULL){
                pq.push(temp);
            }
        }
        //main logic
        while(!pq.empty()){
            ListNode* front=pq.top();
            pq.pop();

            //usko main ll m jod bkl
            if(head==NULL && tail==NULL){
                head=front;
                tail=front;
            }
            //agar ll phele se ban ho matalb  khali nhi ho
            else{
                tail->next=front;
                tail=front;
            }
            //ab wo process ho chuki 
            //agar uske aage koi node h to usko pq m dal bsdk
            if(front->next!=NULL){
                pq.push(front->next);
            }
            
        }
        return head;
        
    }
};