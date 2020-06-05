class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //steps 
        //step1 : finding the first position fffftttt
        //p(X) x>=target
        //find the first t
        int n = nums.size(), lo=0, hi = n-1, mid;
        vector<int> res;
        
        if (n == 0)
            return {-1,-1}; //needed to avoid the runtime error as this is the base case
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;//lomid 
                
            //decision
            if(nums[mid]>=target){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        //sanity check : is it found or not 
        if(nums[lo]!=target){
            return {-1,-1};
        }
            res.push_back(lo);
        
        
        //step 2 find the last part 
        //assumption : element exists -- else step 1 would have returned -1
        //p(x) : x>target
        //ffffftttt last f
        
        lo = 0, hi = n-1;
        while(lo<hi){
            mid = lo + (hi-lo+1)/2;
            if(nums[mid]>target){
                hi = mid -1;
            }
            else{
                lo = mid;
            }
        }
        //sanity check -- dont need it as know the element exists
        res.push_back(lo);
        return res;
        
        
        
        
        
        
        
    }
};