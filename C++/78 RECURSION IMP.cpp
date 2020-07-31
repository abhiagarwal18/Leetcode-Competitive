// class Solution {
// public:
//     vector<vector<int>> f(vector<int>&nums, int start_idx){ //mission statement
        
//         //base step
//         //solution to the smallest subproblem
//         if(start_idx == nums.size())
//             return {{}}; //since last index is a subset of empty set
//         //recursive step
//         //use the recursive relation
//         // f(nums,0) = f(nums,1) U {f(0) U f(nums, 1)} -- has include case and exclude case
//         vector<vector<int>> sub_set = f(nums, start_idx+1) ;
//         vector<vector<int>> res;
//         //exclude case
//         res= sub_set;
//         //include case
//         vector<int>temp;
//         for(int i = 0; i<sub_set.size(); i++)
//         {
//             temp = sub_set[i];
//             temp.push_back(nums[start_idx]);
//             res.push_back(temp);
            
//         }
//         return res;
        
        
        
//     }
    
    
    
    
    
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         return f(nums,0);   
//     }
// };

// TAIL RECURSIVE METHOD  ---- has more recursive calls but lesser time 
class Solution {
public:
    void f(vector<int>&nums, int start_idx, vector<int>currSet, vector<vector<int>>&res){ //mission statement
        //base case 
        //solution to the smallest subproblem
        if(start_idx == nums.size())
        {
            res.push_back(currSet);
            return;
        }
        //recursive case 
        //no contribution case (no individual ele)
        f(nums, start_idx+1, currSet, res);
        //contribution case
        currSet.push_back(nums[start_idx]);
        f(nums, start_idx+1, currSet, res);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>currSet; //leaving it as empty as in the base case the empty set should also be counted
        f(nums,0,currSet, res);   
        return res;
    }
};