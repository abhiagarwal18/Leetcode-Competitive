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
     ListNode * merge(int st, int end, vector<ListNode*>& lists){
         if(st>end) return NULL;
         if(st == end ) return lists[st];
         int m = st +(end-st)/2; 
         ListNode * l1 = merge(st, m, lists);
         ListNode *l2 = merge(m+1, end, lists);
         return merger(l1,l2);
     }
    
    ListNode * merger(ListNode *l1, ListNode *l2){
        if(l1==NULL ) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val){
            l1->next = merger(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merger(l1, l2->next);
            return l2;
        }
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(0, lists.size()-1, lists);    
    }
};


/* PRIORITY QUEUES

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode *head = new ListNode(0) ;
        ListNode* dummy=head;
        for(int i =0; i< lists.size(); i++)
        {
            while(lists[i]!=NULL)
            {
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        while(!pq.empty())
        {
            head->next=new ListNode(pq.top());
            pq.pop();
            head=head->next;
        }
        return dummy->next;
    }
};



/* MY SOLUTION
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> all_numbers;
        
        for(int i = 0;  i<n; i++){
            while(lists[i] != NULL){
                all_numbers.push_back(lists[i]->val);
                cout<<lists[i]->val<<endl;
               lists[i] = lists[i]->next;
            }
        }
        sort(all_numbers.begin(), all_numbers.end());
        for(int i = 0; i<all_numbers.size(); i++)
            cout<<all_numbers[i];
        ListNode * result = new ListNode(0);
        ListNode * headresult = result;
        for(int i = 0 ; i<all_numbers.size(); i++){
            result -> next = new ListNode(all_numbers[i]);
            result = result->next;
        
        }
        return headresult->next;
        
    }
};

*/