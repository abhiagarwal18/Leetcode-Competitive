class Solution {
public:
    int getsum(vector<vector<int>>&prefixSum, int boti, int botj, int len){
       int topi = boti - len;
       int topj = botj-len;
        int sum = 0;
        sum += prefixSum[boti][botj];
        if(topj >=0){ //these ifs are sort of sanity checks 
             sum -= prefixSum[boti][topj];
        }
        if(topi>=0)
            sum -= prefixSum[topi][botj];
        if(topi >=0 && topj >=0 )
            sum += prefixSum[topi][topj];
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        //preprocess to store prefix sum
        int m = mat.size(), n = mat[0].size(), i , j, rowSum = 0;
        int lo,hi,mid,res = 0;
        vector<vector<int>> prefixSum(m,vector<int>(n,0));
        for(i=0; i<m; i++){
            rowSum = 0;
            for(j=0; j<n;j++){
                rowSum += mat[i][j];
                if(i==0)
                    prefixSum[i][j] = rowSum;
                else
                    prefixSum[i][j]= prefixSum[i-1][j]+ rowSum;
            }
        }
        
        //now iterate over all the possible bottom right corners
        for(i=0; i<m;i++){
            for(j=0; j< n; j++){
                //binary search on the length
                //p(x) sum>threshold
                
                lo = 1;
                hi = min(i,j)+1; //since i!=j for many cases
                while(lo<hi){
                    mid = lo + (hi-lo+1)/2;
                        
                    if(getsum(prefixSum, i, j, mid)>threshold)
                        hi = mid -1;
                    else
                        lo = mid;
                }
                //sanity check
                 if(getsum(prefixSum, i, j, lo)<=threshold)
                res = max(res, lo);
            }
        }
        return res;
    
    
    }
};