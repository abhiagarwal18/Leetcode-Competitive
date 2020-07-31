class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //make array of pairs with frequency for each element
        
        int n = nums.size();
        vector<pair<int, int>> map;
        int count = 1;
        
        //first sort it
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i< n-1 ; i++){
            if(nums[i] == nums[i+1])
                count++;
            else
            {
                map.push_back(make_pair(count, nums[i]));
                count = 1;
            }
        }
        
        //add the count for the last element
        
        map.push_back(make_pair(count, nums[n-1]));
        
        //go through first k elements after sorting it
        
        sort(map.rbegin(), map.rend() );
        
        vector<int>ans;
        for(int i = 0; i< k; i++){
            ans.push_back(map[i].second);
        }
        return ans;
        
        
        
    }
};