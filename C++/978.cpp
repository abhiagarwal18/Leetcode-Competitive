class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
    int res = 0, count = 0 ;
    for (int i = 0; i < A.size(); i++) {
        if (i >= 2 && ((A[i-2] > A[i-1] && A[i-1] < A[i]) ||
                       (A[i-2] < A[i-1] && A[i-1] > A[i])) ) {
            count++;
        } else if (i >= 1 && A[i-1] != A[i]) {
            count = 2;
        } else {
            count = 1;
        }
        res = max(res, count);
    }
    return res;
    }
};