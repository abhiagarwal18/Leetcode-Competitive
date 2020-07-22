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

// day 15

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode * last) {
        auto new_head = new ListNode(0); // auto takes care of the data type at the compile time
        while(head != last){
            //reverse the k group
            ListNode *temp = head->next;
            head->next = new_head -> next;
            new_head ->next = head;
            head = temp;
            
        }
        return new_head->next;
                
    }
    
    ListNode * reverseKGroup(ListNode *head, int k){
        auto curr = head;
        for(int i= 0; i<k; i++, curr = curr->next){
            if(!curr) return head; //case where length of list in itself is less than k
        }
        auto new_head = reverse(head, curr);
        head->next = reverseKGroup(curr, k);
        return new_head;
        
        
    }
    
    
};