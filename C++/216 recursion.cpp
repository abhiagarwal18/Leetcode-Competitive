class Solution {
public:
    void f(vector<int>&nums, int startidx, int k, int n, vector<vector<int>>&res, vector<int>currset)
    {   int sz = nums.size();
        //base case
        //either startidx full or k == 0 or n == 0
        if(k==0 && n == 0)
        {
            res.push_back(currset);
            return;
        }
        if(k == 0)
            return;
     if(n<0) return;
     
        //recursive case
        
        for(int i = startidx ; i < sz ; i ++ ){
            currset.push_back(nums[i]);
            f(nums, i+1 , k-1 , n-nums[i] , res, currset );
            currset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i = 1; i <= 9 ; i ++)
            nums.push_back(i);
        vector<vector<int>>res;
        vector<int>currset;
        f(nums, 0, k, n, res, currset);
        return res;
    }
};