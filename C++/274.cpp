class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>counts(n+1,0);
        for(int i = 0; i<n; i++){
            if(citations[i]<n)
            {
                counts[citations[i]]++;
            }
            else
                counts[n]++;
        }
        
        //take cumulative sums
        
        for(int i = n-1; i>=0; i--){
            counts[i] = counts[i]+counts[i+1];
        }
        
        //find the ele with index less than or equal to cumulative
        int ans = 0;
        for(int i = 0; i<n+1; i++){
            if(counts[i] >= i)
                ans= i;
        }
        return ans;
    }
};