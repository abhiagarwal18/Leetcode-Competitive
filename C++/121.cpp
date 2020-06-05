class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, maxsoFar = INT_MIN, profit, res = INT_MIN;
        if(n==0 ) return 0;
        maxsoFar = prices[n-1];
        for(int i = n-2; i>=0; i-- ){
            profit = maxsoFar - prices[i];
            res = max(res, profit);
            maxsoFar = max(maxsoFar, prices[i]);
    }
    return max(0, res);

    } 
};