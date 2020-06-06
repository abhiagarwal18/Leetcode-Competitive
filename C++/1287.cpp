class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n/4;
    /*
        for(int i =0; i<n; i++){
            if(arr[i]==arr[i+1]){
                count++;
                if(count>=target){
                    flag= arr[i];
                }
            }
            else{
                count =0;
                flag =-1 ;
    
            }
        }*/
        for(int i=0; i<n-target; i++){
            if(arr[i]== arr[i+target]){
                return arr[i];
            }
        }
        return -1;
    }
};ƒ