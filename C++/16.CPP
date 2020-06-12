class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
       sort(nums.begin(), nums.end());
        int p1 = 0;
        int currsum = 0, res = nums[0]+nums[1]+nums[2];//CANT INITIATE WITH 0 AS THEN (TARGET-0) WILL MAKE IT ALWAYS THE RES
        while(p1<n-1){
            int p2 = p1+1;
            int p3 = n-1;
            while(p2<p3){
                currsum = nums[p1]+nums[p2]+nums[p3];
                res = (abs(target-currsum) < abs(target - res)) ? currsum : res;
                if(currsum == target)
                    return currsum;
                else if(currsum > target)
                    p3--;
                else
                    p2++;
            }
            p1++;
        }
        return res;
    }
};