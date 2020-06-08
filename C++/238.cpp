class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //preprocessing
        int n = nums.size();
        int i;
        vector<int> forwards(n,0);
        forwards[0] = 1;
        for(int i =1; i<n; i++)
            forwards[i] = forwards[i-1] * nums[i-1];            
        vector<int> backwards(n,0);
        backwards[n-1]= 1;
        for(int i = n-2; i>=0; i--)
            backwards[i]= backwards[i+1] * nums[i+1];
        vector<int>output(n,0);
        for(int i =0; i<n; i++)
            output[i] = forwards[i] * backwards[i];
        return output;
    }  
};