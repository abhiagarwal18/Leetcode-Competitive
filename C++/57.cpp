class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<pair<int,int>> intervalSpace;
        for(int i=0; i<n; i++){
            intervalSpace.push_back(make_pair(intervals[i][0],0));
            intervalSpace.push_back(make_pair(intervals[i][1],1));
        }
            intervalSpace.push_back(make_pair(newInterval[0],0));
            intervalSpace.push_back(make_pair(newInterval[1],1));
        
        //sort
        sort(intervalSpace.begin(), intervalSpace.end(), [=](pair<int,int> &a, pair<int,int> &b){
           if(a.first == b.first)
               return a.second<b.second;
            else
                return a.first<b.first;
        });
        
        //counter to make new intervals
        int counter = 0;
        vector<vector<int>> res;
        for(int i=0; i<intervalSpace.size(); i++){
            if(intervalSpace[i].second== 0)
            {
                counter++;
                if(counter == 1)
                    res.push_back({intervalSpace[i].first});
            }
            else
            {
                counter--;
                if(counter == 0)
                    res[res.size()-1].push_back(intervalSpace[i].first);
            }
        }
        return res;
    }
};