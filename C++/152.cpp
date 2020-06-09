class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxp=nums[0], minp = nums[0],res=nums[0];
        for(int i =1; i<n; i++){
            if(nums[i]>=0){
                maxp = max(maxp*nums[i], nums[i] );
                minp = min(minp*nums[i], nums[i]);
                
                res = max(maxp, res);
            }
            else{
                int tempp = maxp;
                maxp = max(minp*nums[i], nums[i]);
                minp = min(tempp*nums[i], nums[i]);
                res = max(maxp, res);
            }
        }
          
        
        
        return res;
    }
};