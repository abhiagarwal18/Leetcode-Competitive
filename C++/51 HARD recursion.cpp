class Solution {
public:
    void f(int k, vector<bool> &cols,vector<bool>&d1, vector<bool>&d2,vector<string>&currComb, vector<vector<string>>&res){
       int n = cols.size();
        //base case
        //k is the only var
        if(k<0)
        {
            res.push_back(currComb);
            return ;
        }
        //recursive step
        //enumerating possibilities for kth queen in the kth row
        int i ; 
        //go ober the cols
        for( i = 0 ; i <n ; i++){
            //check if i can position the queen at (k,i)
            if(!cols[i] && !d1[i-k+n-1] && !d2[i+k]){
                //valid state
                    cols[i] = true;
                d1[i-k+n-1 ] = true;
                d2[i+k] = true;
                //just add contribution
                currComb[k][i] = 'Q';
                f(k-1, cols, d1, d2, currComb,res);
                //reset for next iterations
                    cols[i] = false;
                d1[i-k+n-1 ] = false;
                d2[i+k] = false;
                //reset befoer next iteration
                currComb[k][i] = '.';
                    
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>cols(n,false);
        vector<bool>d1(2*n-1,false);
        vector<bool>d2(2*n-1,false);
        vector<vector<string>>res;
        vector<string>currComb(n, string(n,'.')); // vector of strings with all characters .
        f(n-1, cols, d1, d2,currComb, res); // n-1 since counting till == 0
        return res;
    }
};