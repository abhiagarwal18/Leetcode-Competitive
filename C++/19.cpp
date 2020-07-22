/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 THESE ARE ALL CONSTRUCTORS TO DEFINE A LISTNODE
 *     ListNode() : val(0), next(nullptr) {}
 eg. ListNode * l = new ListNode() ;
 *     ListNode(int x) : val(x), next(nullptr) {}
 eg. ListNode * l = new ListNode(143);
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 eg. ListNode * l = new ListNode(143, temp);
 
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode * h1 = head;
        ListNode * h2 = head;
        for(int i = 0; i<n ; i++){
            h2 = h2->next;
        }
        if(h2 == NULL ) // that means that this is the next to last node
            return h1->next; //since this means total size of list is n itself
        while(h2 -> next != NULL)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        
        // now h1 points to the node which is one before the nth node from end
        
        h1->next = h1->next->next;
        return head;
        
        
        
        
        
        
        
    }
};