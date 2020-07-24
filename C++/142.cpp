/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       //make a slow and a fast pointer, fast pointer will jump two positions.
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* ans = NULL;
    bool flag = false; //initially assume there isn't any cycle
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            flag = true;
            break;
        }
    }
    //now finding tge beginning point
    fast = head;
    if(flag){ // if there is a cycle
        while(1){
            if(fast==slow){ ans = fast; break; }
            fast =fast->next; slow = slow->next;
        }
    }
    return ans;  
    }
};