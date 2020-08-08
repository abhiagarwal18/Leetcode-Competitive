class Solution {
public:
    int getkpositionnumber(vector<bool>&visited, int m){
        //find the mth univisited smallest number
        int sz = visited.size(); //sz = n+1
        for(int i = 1; i<sz; i++){
            if(visited[i]) continue;
            m--;
            if(m==0) return i;
        }
        return -1;
    }
    void reverseRem(string &s, vector<bool>&visited){
        for(int i = visited.size()-1; i>0; i--){
            if(!visited[i])
                s+= to_string(i);
        }
    }
    
    string getPermutation(int n, int k) {
        vector<int>factorial(n+1,1);
        //fill it
        for(int i = 1 ; i <=n; i++){
            factorial[i] = i * factorial[i-1];
        }
        string res = "";
        int runk = k, temp, rem, q;
        vector<bool>visited(n+1, false);
        
        for(int i = 1; i<=n; i++){
            rem = runk%(factorial[n-i]);
            q =runk/factorial[n-i];
            
            if(rem==0)
            {
                temp = getkpositionnumber(visited, q);
                res+= to_string(temp);
                visited[temp ] = true;
                reverseRem(res, visited);
                return res;
                
            }
            
            else{
                temp = getkpositionnumber(visited, q+1);
                res+= to_string(temp);
                visited[temp] = true;
                runk = rem;
                
            }
        }
        return res;
        
    }
};