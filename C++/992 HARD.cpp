class Solution {
public:
    int lessthank(vector<int>&A, int k ){
        int n = A.size();
        map<int,int>ref;
        int l=0,r=0;
        int count =0;
        while(r<n){
            ref[A[r]]++;
            if(ref.size()>k){
                while(ref.size()>k)
                {
                    ref[A[l]]-=1;
                    if(ref[A[l]]<=0)
                        ref.erase(A[l]);
                    l++;
                 }
            }
            
            count += r-l+1;
            r++;
            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return (lessthank(A,K)-lessthank(A,K-1));
    }
};