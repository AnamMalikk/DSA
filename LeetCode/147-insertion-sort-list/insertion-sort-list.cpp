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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* curr = head->next;
        ListNode* currPrev = head;
        while (curr) {
            ListNode* it = head;
            ListNode* itPrev = NULL;
            while (curr != it && it->val <= curr->val) {
                itPrev = it;
                it = it->next;
            }
            //No insertion 
            if(it==curr){
                currPrev = curr;
                curr=curr->next;
                continue;
            }
            //detach curr
            currPrev->next = curr->next;
            //insert in head position
            if (!itPrev) {
                curr->next = head;
                head = curr;
            } 
            //insert in middle position
            else{
                curr->next = it;
                itPrev->next=curr;
            }
            curr = currPrev->next;
        }
        return head;
    }
};