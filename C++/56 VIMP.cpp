class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>>intervalSpace;
        
        //make an array of all the bounding elements of the interval
        for(int i =0; i<n; i++){
            //push the start of the interval 
            intervalSpace.push_back(make_pair(intervals[i][0], 0));
            //push the end of the corresponding interval
            intervalSpace.push_back(make_pair(intervals[i][1], 1));
        }
        
        //sort the intervalspace
        sort(intervalSpace.begin(), intervalSpace.end(), [=](pair<int,int> &a, pair<int,int>&b){
            //for cases like [1,4],[4,5]
            if(a.first == b.first)
                return a.second < b.second ;//return true s.t. starting element earlier
            else 
                return a.first<b.first;
        });
            
        //run the counter and add to the result 
        int counter =0;
        vector<vector<int>> ans;
        for(int i =0; i<intervalSpace.size(); i++){
            if(intervalSpace[i].second == 0)
            {
                counter++;
                if(counter ==1){
                    ans.push_back({intervalSpace[i].first});
                }
            }
            else
            {
                counter--;
                if(counter == 0){
                    ans[ans.size()-1].push_back(intervalSpace[i].first);
                }
            }
            
        }
        return ans;
        
        
        
        
    }
};