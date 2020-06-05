class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search
        if(matrix.empty())
            return false;        
        int m=matrix.size(), n=matrix[0].size(), lo = 0, hi =(m*n-1),i,j,mid;
        //need to take care of some corner cases
        //case 1 if the entirre matrix is empty 
        
        if(matrix.size()==0) 
            return false;
        if(n==0)
            return false;
        
        
        while(lo<hi){
            mid = lo + (hi-lo+1)/2;
            i = mid/n;
            j = mid%n;
            if(matrix[i][j]>target){
                hi = mid-1;
                
            }
            else
                lo = mid;
            }
    //snity check
    i = lo/n    ;
    j = lo%n;
    if(matrix[i][j]==target)
        return true;
    return false;    }
};