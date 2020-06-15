class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), len = 0, res = 0;
        int p1=0, p2=0;
        while(p1<n){
            p2 = p1;
            if(p2<n-1 && A[p2]<A[p2+1]){
                while(p2<n-1 && A[p2]<A[p2+1])
                    p2++;
            if(p2<n-1 && A[p2]>A[p2+1]){
                while(p2<n-1 && A[p2]>A[p2+1])
                    p2++;
             len = max(len, p2-p1+1);}
            
        }
            p1 = max(p1+1, p2);
            
    }
        return len;}
};