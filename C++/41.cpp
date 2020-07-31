class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //O(n) solution number 2
        
        //put K at K-1 index
        
        int n = nums.size();
        if(n==0) return 1;
        
        for(int i = 0; i<n ; i++){
            
            int val = nums[i];
            while(val>0 and val<=n and val!= nums[val-1])
            {
                //replace it and update the val
                
                int temp = nums[val-1];
                nums[val-1] = val;
                val = temp; //loop will now run for it if it satisfies the conditions
                            }
            }
        
        for(int i = 0; i<n; i++)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
        
        
    }
};

/*class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int maxel = 0,minel=INT_MAX, numpos= 0;
        for(int i =0; i<n; i++)
        {maxel = max(maxel, nums[i]);
            if(nums[i]>0)
                minel = min(minel, nums[i]);
         if(nums[i]>0)
             numpos++;
        }
        if(minel > 1)
            return 1;
        else if( minel==maxel)
        {
            return maxel+1;
        }
        else 
        {   int flag = 0;
            for(int i = minel; i<=maxel; i++){
                if (find(nums.begin(), nums.end(),i) == nums.end())
                    {flag = i;
                    break;}
                    
            }
         
            if(flag==0)
                return maxel+1;
         else
             return flag;
         
        }
    return -1;
    }
    
};*/