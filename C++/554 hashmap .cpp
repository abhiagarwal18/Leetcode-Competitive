class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), i, j,pos; //num of rows
        unordered_map<int, int>m; //for frequency and position
        for(i = 0; i<n; i++){ 
            pos = 0;
            for(j = 0; j<wall[i].size()-1; j++) //wall-1 since dont need to consider the last position
            {pos+=wall[i][j];
            m[pos]++;}
        }
    
    int maxCount = 0;
    for(auto it = m.begin(); it!=m.end(); it++){
    maxCount = max(maxCount, it->second);
}
        
return (n-maxCount);
}
};