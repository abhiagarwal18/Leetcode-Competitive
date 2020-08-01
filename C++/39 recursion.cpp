class Solution {
public:
    void f(vector<int>&nums, int startIdx, int target, vector<vector<int>>&res, vector<int>currset )
    {
        int n = nums.size(), i = startIdx+1;
        //base case
        //either end is reached with target zero then return the final set
        //or sum > target or end is reached then no answer
         if(startIdx == n || target<0 )
             return;
        if(target == 0)
        {
            res.push_back(currset);
            return;
        }
        
        
        //recursive case
        //finding the contribution with the smallest no. at beginning
        
        for(i = startIdx; i<n; i++){
            currset.push_back(nums[i]);
            f(nums, i, target-nums[i], res, currset);
            currset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>res;
        vector<int>currset;
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, target, res, currset);
        return res;
    }
};