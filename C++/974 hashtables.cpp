class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        //key is remainder that pref sum gives on div with k
        unordered_map<int, int>m;
        int cumSum = 0, r3,res=0;
        m[0] = 1; //vimp : means count of prefix sums with remainder zero is 1 (empty array)
        for(int j = 0; j<n; j++){
            cumSum += A[j];
            r3 = cumSum%K;
            //r3-r2 = 0,k,-k
            //r2 = r3, r3+k, r3-k
            res += m[r3];
            
            res += m[r3-K];
            
            res+= m[r3+K];
            
            //put remainder in the map
            m[r3]++;
            
            
        }
        return res;
        
    }
};