class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int first = INT_MAX;
        int sec = INT_MAX;
        int n = nums.size();
        if(n==1)
            return nums;
        //since now dividing into parts using two sticks sort of
        for(int i =0; i<nums.size(); i++){
            if(nums[i]==first)
                cnt1++;
            else if(nums[i]==sec)
                cnt2++;
            else if(cnt1==0)
            {first = nums[i];
            cnt1++;}
            else if(cnt2==0){
                sec = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        //checking loop
        cnt1 =0 ;
        cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == first)
                cnt1++;
            if(nums[i] == sec)
                cnt2++;
        }
        
        vector<int> vec;
        if(cnt1>n/3)
            vec.push_back(first);
        if(cnt2>n/3)
            vec.push_back(sec);
        return vec;
    }
};