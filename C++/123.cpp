class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),i;
        //preprocessing
        vector<int> suffix(n,1);
        suffix[n-1] = prices[n-1];
        //fill this suffix array
        for(i = n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], prices[i]);
        }
        
        // step two : assuming b2 on the ith day get the max proit 
        int profit, minsoFar = min(prices[0], prices[1]);
        int currprofit ;
        int netprofit;
        profit = max(0, prices[1]-prices[0]);
        int res = profit;
        for(i=2; i<n; i++)
        {
            //assuming that you buy for the second time on this day 
            if(i<n-1)
            currProfit = max(0,suffix[i+1] - prices[i]);
            else 
                currProfit = 0;
            netprofit = currProfit + profit;
            res = max(res, netProfit);
            //update the running profit 
            profit = max(profit, prices[i]-minsoFar);
            minsoFar = min(minsoFar, prices[i]);
        }
        
        return netprofit;
        
    }
};