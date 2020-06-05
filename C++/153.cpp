class Solution {
public:
    int findMin(vector<int>& nums) {
        //fffftttt
        //p(x): A[i] < A[0]
        int n = nums.size(),lo=0, hi = n-1, mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2; 
                
            if(nums[mid]<nums[0])
                hi = mid;
            else
                lo = mid+1;
            
        }
        //sanity check : critical here : array is not rotated about the pivot
        if(nums[lo]<nums[0])
            return nums[lo];
        
        return nums[0];
        
    }
};