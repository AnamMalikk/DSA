/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        // method 1 => clone random with with iteration 
        Node* headCopy = new Node(0);
        Node* tailCopy = headCopy,*temp = head;
        // clone the original list with next pointer only
        while(temp){
            tailCopy->next = new Node(temp->val);
            tailCopy = tailCopy->next;
            m[temp] = tailCopy;
            temp = temp->next;
        }
        // rearrange the pointers
        temp = head;
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        tailCopy = headCopy;
        // now iterate over the original list to find random pointers using unorderd map
        while(temp){
            tailCopy->random = m[temp->random];
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        return headCopy;
    }
};