class Solution {
public:
    int sumarr(int lo, vector<int>&nums){
        int sum=0;
        for(int i =0; i<nums.size(); i++){
            sum+=(nums[i]+lo-1)/lo;
        }
        cout<<sum<<endl;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //fffftttt
        //ss = divisior
        int n=nums.size(), lo = 1, hi = *max_element(nums.begin(), nums.end());
        int mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            cout<<"mid = "<<mid<<endl;  
            if(sumarr(mid, nums)<=threshold){
                hi = mid;
            }
            else
                lo = mid+1;
        }
        return lo;
    }
};