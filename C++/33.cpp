class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        
        //step 1 : find pivot
        
        int lo=0, hi=n-1, mid;
        while(lo<hi){
            mid =lo+(hi-lo)/2;
                
            if(nums[0]>nums[mid]){
                hi = mid;
            }
            else
                lo = mid+1;
        }
        
        int pivot = 0;
        if(nums[lo]<=nums[0]){
            pivot =lo;
             if(target==nums[pivot]){
            return pivot;
        }
        else if(target >=nums[0]){
            lo=0;
            hi = pivot-1;
            while(lo<hi){
                mid = lo + (hi-lo)/2;
                if(nums[mid]>=target){
                    hi = mid;
                }
                else
                    lo = mid+1;
            }
            if(nums[lo]== target)
                return lo;
            else
                return -1;
        }
        
        else if(target < nums[0]){
            lo = pivot;
            hi= n-1;
            while(lo<hi){
                mid = lo +(hi-lo)/2;
                if(nums[mid]>=target){
                    hi = mid;
                    
                }
                else
                    lo = mid +1 ;
            }
            if(nums[lo]== target)
                return lo;
            else
                return -1;
        }
        }
        else {
            lo = 0;
            hi = n-1;
            while(lo<hi){
                mid = lo +(hi-lo)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid]>target){
                    hi = mid;
                }
                else
                    lo = mid+1;
            }
            if(nums[lo]== target )
                return lo;
            else 
                return -1;
        }     
        return -1;
    }
};