/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int lo =0,hi = n-1, mid;
        while(lo<hi){
            mid = lo+ (hi-lo)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                hi = mid;
            else
                lo = mid+1;
                
        }
        cout<<"peak is"<<lo;
        vector<int>temp(2,0);
        int peak = lo;
        lo =0, hi = peak;
        while(lo<hi){
            mid = (hi+lo)/2;
            if(mountainArr.get(mid)>=target)
                hi = mid;
            else
                lo = mid+1;
        }
        int f = mountainArr.get(lo);
        cout<<endl<<"f"<<f;
        if(f== target){
            temp[0]=lo;
            cout<<endl<<temp[0];
        }
        else
            temp[0]=-1;
        
        lo = peak;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<=target)
                hi = mid;
            else
                lo = mid+1;
        }
        if(mountainArr.get(lo)== target){
            temp[1]= lo;
        }
        else
            temp[1]=-1;
        
        
        if(temp[0]!=-1)
            return temp[0];
        else if(temp[0]==-1 && temp[1]!=-1)
            return temp[1];
        else return -1;
        
        
        
        
        
    }
};