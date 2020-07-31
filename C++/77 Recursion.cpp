// //TLE SOLUTION
// // class Solution {
// // public:
// //     void f(vector<int>&arr, int startidx, int k, vector<int>currSet, vector<vector<int>>&res){
// //         //Base Step
// //         //found a solution
// //         if(k==0)
// //         {
// //             res.push_back(currSet);
// //             return ;
// //         }
// //         //empty subarray and k>0 => no solution found
// //         if(startidx == arr.size() )
// //             return;        
// //         //recursive step
// //         //exclude
// //         f(arr, startidx+1, k, currSet, res);
// //         //include step
// //         currSet.push_back(arr[startidx]);
// //         f(arr, startidx+1, k-1, currSet, res );
// //     }
// //     vector<vector<int>> combine(int n, int k) {
// //         vector<int> arr;
// //         for(int i = 1; i<=n; i++)
// //             arr.push_back(i);
// //         vector<int>currSet;
// //         vector<vector<int>>res;
// //         f(arr, 0, k, currSet, res);
// //         return res;
// //     }
// // };



// //TLE SOLUTION
// // class Solution {
// // public:
// //     void f(vector<int>&arr, int startidx, int k, vector<int>currSet, vector<vector<int>>&res){
// //         //Base Step
// //         //found a solution
// //         if(k==0)
// //         {
// //             res.push_back(currSet);
// //             return ;
// //         }
// //         //empty subarray and k>0 => no solution found
// //         if(startidx == arr.size() )
// //             return;        
// //         //recursive step
// //         //exclude
// //         f(arr, startidx+1, k, currSet, res);
// //         //include step
// //         currSet.push_back(arr[startidx]);
// //         f(arr, startidx+1, k-1, currSet, res );
// //     }
// //     vector<vector<int>> combine(int n, int k) {
// //         vector<int> arr;
// //         for(int i = 1; i<=n; i++)
// //             arr.push_back(i);
// //         vector<int>currSet;
// //         vector<vector<int>>res;
// //         f(arr, 0, k, currSet, res);
// //         return res;
// //     }
// // };

// //PRUNING
// class Solution {
// public:
//     void f(vector<int>&arr, int startidx, int k, vector<int>currSet, vector<vector<int>>&res){
//         //Base Step
//         //found a solution
//         if(k==0)
//         {
//             res.push_back(currSet);
//             return ;
//         }
//         //empty subarray and k>0 => no solution found
//         if(startidx == arr.size() )
//             return;        
//         //recursive step
        
//         //PRUNING
//         if(k> arr.size() - startidx) //k> size of the subarray
//             return ; //do nothing
        
//         //exclude
//         f(arr, startidx+1, k, currSet, res);
//         //include step
//         currSet.push_back(arr[startidx]);
//         f(arr, startidx+1, k-1, currSet, res );
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<int> arr;
//         for(int i = 1; i<=n; i++)
//             arr.push_back(i);
//         vector<int>currSet;
//         vector<vector<int>>res;
//         f(arr, 0, k, currSet, res);
//         return res;
//     }
// };

// ITERATIVE ALGO
class Solution {
public:
    void f(vector<int> &nums, int startIdx, int k, vector<int> currSet, vector<vector<int>> &res){
        // Base step
        // Found a solution
        // 2D subproblem
        // D1 empty D2 non-empyt
        // D1 non-empty D2 empty
        // D1 empty D2 empty
        
        if(k == 0) {
            res.push_back(currSet);
            return;
        }
        
        // k > 0 && vector was empty
        if(startIdx == nums.size())
            return;
        
        // Pruning
        int n = nums.size();
        if(k > n-startIdx)
            return;
        
        // Recursive step
        int i;
        // Iterate over all possibilities of the first element
        // [2, 3, 4]
        // [start=5, 6, 7, 8, 9]
        for(i = startIdx; i < nums.size(); i++){
            // Consider i as the first element
            currSet.push_back(nums[i]);
            f(nums, i+1, k-1, currSet, res);
            currSet.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        int i;
        
        for(i = 1; i <= n; i++)
            nums.push_back(i);
        
        vector<vector<int>> res;
        vector<int> currSet;
        
        f(nums, 0, k, currSet, res);
        
        return res;
    }
};
