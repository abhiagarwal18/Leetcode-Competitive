class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum =0;
        for(int i=0; i<n; i++){
            sum+= A[i];
        }
        int target_sum = sum/3;
        if(sum%3 !=0 ){
            return false;
        }
        int lo =0, hi = n-1, sumlo =0, sumhi = 0;
        sumlo = sumlo+ A[lo];
        sumhi = sumhi + A[hi];
        while(lo<hi){
            
            if(sumlo == target_sum && sumhi == target_sum){
                if(hi-lo>1)
                    return true;
                else
                    return false;
            }
            else if(sumlo== target_sum && sumhi!=target_sum){
                hi--;
                sumhi += A[hi];
            }
            else if(sumhi== target_sum && sumlo != target_sum){
                lo++;
                sumlo += A[lo];
            }
            else{
                lo++;
                hi--;
                sumlo = sumlo + A[lo];
                sumhi = sumhi + A[hi];
            }
        }
        return false;
}};