class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>temp(A.size(), 0);
        for(int i=0; i<A.size(); i++){
            temp[i]  = A[i]*A[i];
        }
        sort(temp.begin(), temp.end());
        return temp;
    }
};