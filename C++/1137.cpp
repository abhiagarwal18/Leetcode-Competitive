// class Solution {
// public:
//     int tribonacci(int n) {
//         int sum; 
//         if(n< 0)
//             return -1;
//         if(n==0)
//             return 0;
//         if(n==1 || n==2) return 1;
//         int t0 = 0;
//         int t1 = 1;
//         int t2 = 1;
//         for(int i = 2 ; i < n; i++){
//             sum = t0+t1+t2;
//             t0 = t1;
//             t1 = t2;
//             t2 = sum;
//         }
//         return sum;
//     }
// };

//ACC TO RECURSION STEPS
class Solution {
public:
    void f(int n,int prev1,int prev2,int prev3,int &res)
    {
        if(n==0)
            res=0;
        else if(n==1||n==2)
            res=1;
        else if(n>=3)
        { 
            for(int i=3;i<=n;i++)
            {
            res=prev1+prev2+prev3;
            prev3=prev2;
            prev2=prev1;
            prev1=res;
            }
        
        } 
    }
    int tribonacci(int n) {
        
        int res;
        f(n,1,1,0,res);
        return res;
    }
};