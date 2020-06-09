class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n ==1)
            return ;
        int i =0;
        for( i = n-1; i>0; i--){
            if(nums[i-1]<nums[i])
            {
                break;
            }
        }
        if(i==0 )
        {
            sort(nums.begin(), nums.end());
            return ;
        }
        
        else{
            
            int flag = n-1;
            for(flag = n-1; flag>=i; flag--){
                if(nums[flag]>nums[i-1])
                    break;
            }
            
            int temp = 0;
            temp = nums[i-1];
            nums[i-1] = nums[flag];
            nums[flag] = temp;
            sort(nums.begin()+i, nums.end());
            return ;

            
        }  
    }
};