class Solution {
public:
    int trips(vector<int>&weights, int capacity){
        int sum = 0;
        int i =0, n =weights.size(), currsum = 0;
        while(i<n){
            if(currsum+weights[i]>capacity){
                sum++;
                currsum = 0;
            }
            else {
                currsum +=weights[i];
                i++;
            }
            
            
            }
        return (++sum); //incrementing here since the last trip is not getting counted as it always goes to the else part
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        //find out the boundai3s of the search space
        int n = weights.size(), i, maxelt = INT_MIN, sumelts=0;
        for(i=0; i<n; i++){
            maxelt = max(maxelt, weights[i]);
            sumelts+= weights[i];
        }
        int lo = maxelt, mid,hi = sumelts;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            
            if(trips(weights, mid)<= D)
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};