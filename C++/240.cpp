class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //needed to add this case else a runtime error
        if(matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size(), i,j;
        i =0;
        j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j] == target) 
                return true;
            else if(matrix[i][j] <target)
                i++;
            else
                j--;
        }
        return false;
    }
};