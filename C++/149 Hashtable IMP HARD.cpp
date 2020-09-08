class Solution {
public:
//     int gcd(int a, int b){
//         if(a==0) {return b;}
        
//         return gcd(a%b, a);
//     }
    int maxPoints(vector<vector<int>>& points) {
        
        
        int n = points.size(),i,j,dy,dx,dups=0,res=0,g, currMax =0;
        string slope;
        unordered_map<string, int>m;
        //enumerating all the lines with i as on of the points
        for(i=0; i<n; i++){
            //second point for this i
            dups= 1; //to count the startig point too
            currMax =0;
            m.clear();
            for(j=i+1; j<n; j++){
                dy = points[j][1]- points[i][1];
                dx = points[j][0] - points[i][0];
                if(dy==0 && dx==0)
                {dups++; //for handling duplicates of a poitn
                 continue;}
                
                if(dx!=0 ){
                    g= __gcd(dy,dx);
                dy /=g;
                dx /= g;
                }
                if(dx==0)
                    dy=1;
                slope = to_string(dy)+"/"+ to_string(dx);
                m[slope]++;
                currMax = max(currMax, m[slope]);//excluding the duplicates
                
                
            }
                currMax = currMax+dups; //to take the case where duplicates also present
            res = max(res, currMax);
        }
        return res;
    }
};