class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > res( K  , vector<int> (2, 0)); 
        int n = points.size();
        sort(points.begin(), points.end(), [=](vector<int>&a, vector<int>&b){
            
            return (sqrt((a[0]*a[0]) + a[1]*a[1]) < sqrt((b[1]*b[1])+(b[0]*b[0])));
        });
        
        for(int i =0 ; i<K; i++){
            res[i][0] = points[i][0];
            res[i][1] = points[i][1];
        }
        
        return res;
        
    }
};