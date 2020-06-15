class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int N = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < N; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int & ability : worker) {
            while (i < N && ability >= jobs[i].first)
            {best = max(jobs[i++].second, best);
             cout<<i<<endl;}
            res += best;
            cout<<"ability  "<<ability<<" i "<<i<<" best "<<best<<endl;
        }
        
        return res;
    }};
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//         //combine difficulty and profits into one vector
//         vector<pair<int,int>> jobs;
//         for(int i=0;i<difficulty.size(); i++){
//             jobs.push_back(make_pair(difficulty[i], profit[i]));
//         }
//         sort(jobs.begin(), jobs.end());
//         sort(worker.begin(), worker.end());
//         //do binary search for the worker    
//         int res=0;
//         for(int i=0; i<worker.size(); i++){
//             int hisbest = 0;
//             for(int j=0; j<difficulty.size(); j++){
//                 if(worker[i]>= jobs[j].first)
//                     hisbest = max(hisbest, jobs[j].second);
//             }
//             res+= hisbest;
//         }
            
            
            
            
// //            int target_level = worker[i];
// //             int lo = 0, hi = difficulty.size()-1,mid;
// //             while(lo<hi){
// //                 mid = lo + (hi-lo+1)/2;
                
// //                 if(jobs[mid].first>target_level)
// //                     hi= mid-1;
// //                 else
// //                     lo = mid;
// //             }
            
// //             int needed_i;
// //             if(jobs[lo].first <= target_level)
// //                 sum+= jobs[lo].second;
// //             else
// //                 sum+=0;
            
          
// //        } 
//     return res;
//     }
// };