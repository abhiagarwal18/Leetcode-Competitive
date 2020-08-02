class Solution {
public:
    bool solve(vector<int>& nums,vector<bool>& used, int k,int sum,int target,int index){
        if(k==1) return true;
        if(sum==target) return solve(nums,used,k-1,0,target,0);
        for(int i=index;i<nums.size();i++){
            if(!used[i]){
                if(sum+nums[i]<=target){
                    used[i]=true;
                    if(solve(nums,used,k,sum+nums[i],target,i+1)) return true;
                    used[i]=false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target=0;
        for(auto i:nums) target+=i;
        if(target%k != 0) return false;
        target/=k;
        vector<bool> used(nums.size(),false);
        return solve(nums,used,k,0,target,0);
    }
};