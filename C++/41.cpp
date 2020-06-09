class Solution {
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
    
};




// better solution
class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};










