class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // SOLUTION -1 
//         int n = intervals.size();
//         if(n==0)
//             return 0;
//         // sort wrt the starting points and set a counter -- if the end of previous more or equal than first of next then overlapping
        
//         sort(intervals.begin(), intervals.end(), [=](vector<int> &a, vector<int> &b){
//             if(a[1]==b[1])
//                 return a[0]<b[0];
//             else 
//                 return a[1]<b[1];
//         });
        
//         int counter = 1;
//         int prevend = intervals[0][1];
//         for(int i = 1; i<intervals.size(); i++){
//             if(intervals[i][0]>= prevend)
//             {counter++;
//                 prevend = intervals[i][1];            
//             }   
            
//         }
//         //counter here gives the length of the non overlapping intervals present here
//         return n-counter;
        
        //Class solution
        int n = intervals.size(), i, j, count = 0, currIntervalidx;
        
        sort(intervals.begin(), intervals.end(), [=](vector<int> &a, vector<int> &b){
            // sort on the basis of end times
            // in case of clash order shouldnt matter
            return a[1]<b[1];
        });
        
        i=0 ;
        while(i<n){
            //pick this interval
            currIntervalidx = i;
            //remove all the overlapping intervals
            j = currIntervalidx +1;
            while(j<n){
                if(intervals[j][0] < intervals[currIntervalidx][1])
                    count ++;
                else
                    break;
                j++;
            }
            i = j;
        }
        return count;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};