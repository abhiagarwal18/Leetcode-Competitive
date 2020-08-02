class Solution {
    void permuteUniqueHelper(int currIdx, vector<bool> &used, vector<int> &nums, vector<int> &contri, vector<vector<int>> &ans){
        int n = used.size();
        //base case
        if(currIdx==n){
            ans.push_back(contri);
            return;
        }
        //recusrive case
        for(int i = 0; i<n;i++){
            if(!used[i]){
                used[i] = true;
                contri.push_back(nums[i]);
                permuteUniqueHelper(currIdx+1, used, nums, contri, ans);
                used[i]=false;
                contri.pop_back();
                int j=i+1;
                while(j<n && nums[j]==nums[j-1])
                    j++;
                i=j-1;
            }
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> contri;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        permuteUniqueHelper(0,used,nums,contri,ans);
        return ans;
    }
};