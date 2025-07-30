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
        unordered_map<int,int>mpp;
        ListNode* temp=head;
        while(temp!=nullptr){
            mpp[temp->val]++;
            temp=temp->next;
        }
        ListNode * dummy= new ListNode(0);
        ListNode *current =dummy;
        temp=head;

        while(temp!=nullptr){
            if(mpp[temp->val]==1){
                current->next=new ListNode(temp->val);
                current =current ->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};