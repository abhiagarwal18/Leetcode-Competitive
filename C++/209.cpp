class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
       int n = nums.size();
        if(n<=0)
            return 0;
        int p1=0, p2=0;
        int sum = nums[0];
        int minlen = INT_MAX;
        while(true){
            if(p1<n && sum>=s)
            {
             minlen = min(minlen, p2-p1+1);
                sum -= nums[p1++];//removal
        }
            else if(p2<n-1 && sum<s){
                sum+= nums[++p2];
            }
            else
                break;
      
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};