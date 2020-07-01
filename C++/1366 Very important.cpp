class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size()==1)
            return votes[0];
        int voters = votes.size();
        int numofteams = votes[0].size();
        vector<vector<int>>temp(256, vector<int>(numofteams, 0));
        
        //populate the 2-D array
        
        for(int i =0; i<voters; i++){
            for(int j =0; j<numofteams; j++){
                temp[(int)votes[i][j]][j]++;
            }
        }
        
        string ans =votes[0];
        sort(ans.begin(), ans.end(), [=](char &a, char &b){
            for(int i=0; i<numofteams; i++)
                if( temp[a][i] != temp[b][i] )
                    return temp[a][i] > temp[b][i];
            
            return a<b;
            
            
        });
            
        return ans;    
    }
};