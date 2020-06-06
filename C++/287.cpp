class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //search space : 
        int n = nums.size(), lo =1, hi=n;
        int mid =0;
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            
                
            int count =0;
            for(int i=0; i<n; i++){
                if(nums[i]<=mid){
                    count++;
                }
                
            }
            if(count <= mid ){
                lo = mid + 1;
            }
            else
                hi = mid;
        }
        
        return lo;
    }
};