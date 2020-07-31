class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int flag = -1;
        for(int i = 0; i<n-1; i++)
        {
            if(A[i]>A[i+1])
                flag = i;
        }
        if(flag == -1)
            return A;
        int j=flag+1;
        for(int m = flag+2; m<n; m++){
            if(A[m] < A[flag] && A[m] > A[j])
                j = m;
        }
        int temp = A[flag];
        A[flag] = A[j];
        A[j] = temp;
        return A;
    }
};