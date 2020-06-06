class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int lo=0,hi = INT_MIN,mid;
        for(int i =0; i<n; i++){
            hi = max(hi, arr[i]);
        }
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            
            int temp_sum =0;
            for(int i=0; i<n; i++){
                if(arr[i]>mid)
                    temp_sum += mid;
                else
                    temp_sum += arr[i];
            }
            //fffftttt
            //last f
            if(temp_sum >= target)
                hi = mid;
            else
                lo = mid+1;
                    
            }
        
        int s1=0,s2=0;
        for(int v:arr) s1 += (v>lo)?(lo):v, s2 += (v>lo-1)?(lo-1):v;
        
        return (abs(s2-target) <= abs(s1-target)) ? lo-1 : lo;
    }
    };