class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> ans;
        for(int i =0; i<nums.size(); i++){
            //implement sort of monotonically decreasing stack
            while(!deq.empty() && deq.back()<nums[i]){
                deq.pop_back();
            }
            
            //push the element now
            deq.push_back(nums[i]);
            
            //start adding to ans array if and only if it is atleast k steps in front of the beginning
            if(i>=k-1){
                ans.push_back(deq.front());
                
                //delete from teh front of the deque if the size is now full
                if(!deq.empty() && deq.front() == nums[i-k+1]) deq.pop_front();
            }
        }
        
        return ans;

    }
};