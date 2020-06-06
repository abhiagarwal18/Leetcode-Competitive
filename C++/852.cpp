class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // FFFFTTTT
        //p(x) A[x]-A[x-1]<0
        
        int n = A.size(), lo=0, hi = n-1;
        if(n<3)
            return -1;
        
        int mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
                
            if(A[mid+1]-A[mid]<0){
                hi = mid;
            }
            else
                lo = mid+1;
            
        }
        
        //sanity check
        if(A[lo+1]-A[lo]<0) //no need OF A SANITY CHECK HERE !
            return lo;
        return -1;
        
        
    }
};