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
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(true){
            if(fast->next!=NULL){
                if(fast->next->next!=NULL){
                    fast = fast->next->next;
                    slow = slow->next;
                }
                else{
                    slow = slow->next;
                    break;
                }
            }
            else{
                break;
            }
        }
        return slow;
    }
};