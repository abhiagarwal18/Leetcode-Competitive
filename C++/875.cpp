class Solution {
public:
    
    int timetoeat(vector<int>& piles, int mid){
        int time =0;
        int sum=0;
        for(int i =0; i<piles.size() ; i++){
            if(piles[i]<=mid)
                time++;
            else 
                time = time + piles[i]/mid + 1;
        }
        return time;
    }
    
    
    
    
    int minEatingSpeed(vector<int>& piles, int H) {
        // ss : number of hours 
        int n = piles.size(), i, maxelt = INT_MIN;
        for(i=0; i<n; i++){
            maxelt = max(maxelt, piles[i]);
        }
        int lo = 1, mid,hi = maxelt;
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
                
            if(timetoeat(piles, mid) <= H)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return lo;
        
    }
};