class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
         int curr_zeroes = 0, max_len = 0;
        for(int p1=0, p2=0; p2<A.size();){
            if (A[p2]==1 || curr_zeroes < K){
                curr_zeroes += A[p2++]==0?1:0;   
            }
            else{
                curr_zeroes -= A[p1++]==0?1:0;
            }
            max_len = max(p2-p1, max_len);
        }
        return max_len;
    }
};