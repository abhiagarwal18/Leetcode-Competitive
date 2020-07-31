class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<bool>rows(n, false); //true iff more than one present in thta row
        vector<bool>cols(m, false);
        
        int count =0;
        for(int i =0; i<n; i++){
            count =0;
            for(int j=0; j<m; j++){
                if(grid[i][j])
                    count++;
            }
            if(count>1)
                rows[i]=true; //set true iff for that row no. the count >1
        }
        
        //populate wrt more than one servers in that col
        for(int i=0; i<m; i++){
            count = 0;
            for(int j = 0; j<n; j++)
                if(grid[j][i])
                    count++;
            if(count>1)
                cols[i]= true;
        }
        
        //final run
        
        int res=0;
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]&& (rows[i]||cols[j]))
                    res++; //count iff have one more server in the same row or column
            }
        }
        
        
        return res;
        
        
        
        
        
        
    }
};