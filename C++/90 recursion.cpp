//M1 --- group on the basis of SMALLEST ELEMENT !

// class Solution {
// public:
//     void subsetsWithDupHelper(vector<int> &nums, int startIdx, vector<vector<int>> &res, vector<int> currSet){
//         // Base case
//         int n = nums.size();
//         if(startIdx == n){
//             res.push_back(currSet);
//             return;
//         }
        
//         // Recursive step
//         // Decision: Include it 0 or more times
        
//         // Let's find out the first index which contains a different
//         // element
//         int i, j;
//         i = startIdx+1;
//         while(i < n && nums[i] == nums[i-1]) i++;
        
//         j = i;
        
//         // Include 0 times
//         subsetsWithDupHelper(nums, j, res, currSet);
        
//         // Include 1 or more times
//         for(i = startIdx; i < j; i++){
//             currSet.push_back(nums[i]);
//             subsetsWithDupHelper(nums, j, res, currSet);
//         }
        
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> currSet;
        
//         sort(nums.begin(), nums.end());
        
//         subsetsWithDupHelper(nums, 0, res, currSet);
        
//         return res;
//     }
// };
//M2 -- grouping on the basis of the smallest i in each group
class Solution {
public:
    void func(vector<int> &nums, int strtindx, vector<int> curset , vector<vector<int>> &res){
        int n=nums.size(),i;
        //base case is same
        if(strtindx==n){
            res.push_back(curset);
            return;
        }

        //none is smallest
        func(nums,n,curset,res);
        
        //ith is the smallest
        for(i=strtindx;i<n;i++){
            //if duplicate element
            if(i>strtindx && nums[i]==nums[i-1]) continue;
            //unique element found at i
            curset.push_back(nums[i]);
            
            func(nums,i+1,curset,res);
            
            curset.pop_back();
        }
        
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> curset;
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        func(nums,0,curset,res);
        
        return res;
        
    }
};