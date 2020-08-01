class Solution {
public:
    void f(vector<int>&nums, vector<bool>&visited, vector<vector<int>>&res, vector<int>currset){
        int n = nums.size(), i;
        //base case
        //when all are visited
        //m1 all ele should be true in visited
        //m2 currset should have all ele -- size of currset = n
        if(currset.size() == n)
        {
            res.push_back(currset);
            return;
        }
        
        //recursive case
        //iterate over each subsequence by marking all  unvisited ele as visited for a time
        //iterate over each i as the smallest for a given case of visited
        for(i = 0; i<n; i++){
            if(!visited[i]){ //temporarily get a new subsequence by visiting it with it as the first ele of permutation
                visited[i] = true;
                currset.push_back(nums[i]);
                f(nums, visited, res, currset);
                //bring it back to original state
                visited[i] = false;
                currset.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>currset;
        vector<bool>visited(nums.size(),false);
        f(nums, visited, res, currset);
        return res;
    }
};