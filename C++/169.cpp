class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //m-1 using O(n) space
        //m2 using no extra space --VOTING ALGORITHM
        
        int count=0;
        int ans=0;
        for(int i = 0; i< nums.size(); i++){
            if(count ==0){
                ans = nums[i];
                count++;
            }
            else if(ans == nums[i])
                count++;
            else
                count--;
        }
        return ans;
        
        
    }
};