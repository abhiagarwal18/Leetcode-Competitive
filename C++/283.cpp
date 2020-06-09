class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numz = 0;
        int n = nums.size();
        for(int i : nums)
            if(i ==0)
                numz++;
        int diff = n-numz,i=0,j=0;
        while( j <diff)
       {
            if(nums[i]!=0)
            {nums[j] = nums[i];
             j++;
             }   
            i++;
        }
        
        for(i=diff; i<n; i++)
            nums[i]=0;
        
    }
};