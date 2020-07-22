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
    ListNode* oddEvenList(ListNode* head) {
        //check for an empty list
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode * oddhead = new ListNode();
        ListNode * oddtail = oddhead;
        ListNode * evenhead = new ListNode();
        ListNode * eventail = evenhead;
        
        ListNode * curr = head;
        bool isOdd = true;
        while(curr != NULL){
            if (isOdd){
                oddtail -> next= curr            ;
                oddtail = oddtail->next;
                }
            else
            {
                eventail ->next = curr;
                eventail = eventail->next;
            }
            isOdd = !isOdd;
            curr = curr->next;
            eventail->next = NULL;
            
        }
        oddtail->next = evenhead->next; //because evenhead in itself contains the 0 value, it points to the first even node in the original linked list 
        return oddhead->next;
    }
};