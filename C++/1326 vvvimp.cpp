class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // make pairs of start and end times for all taps
        // sort wrt to start times
        //for each interval, remove those which lie inside the earlier one's 
        
        int num = ranges.size();
        vector<pair<int,int>>intervals(num, make_pair(0,0));
        for(int i = 0; i<num; i++)
        {
            intervals[i].first = (i-ranges[i] >=0)? (i-ranges[i]) : 0;
            intervals[i].second = (i+ranges[i] <=n ) ? (i+ranges[i]):n;
        }
        
        // sort the pairs
        sort(intervals.begin(), intervals.end(), [=](pair<int,int>a, pair<int,int>b){
            if(a.first!=b.first)
                return a.first<b.first;
            else
                return a.second < b.second;
        });
            
        //iterate for the result
         int count = 0, start_time = 0, end_time = 0, i = 0;
        
        while (end_time < n) {
            for (; i < intervals.size() && intervals[i].first <= start_time; i++) {
                end_time = max(end_time, intervals[i].second);
            }
            if (start_time == end_time) return -1;
            start_time = end_time;
            count++;
        }
        return count;
        
        
    }
};