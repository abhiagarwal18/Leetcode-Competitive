class Solution {
public:
    int maximumGap(vector<int>& nums) {
     //basic approach
        
        // int n = nums.size();
     //    if(n<2)
     //        return 0;
     //    int diff = INT_MIN;;
     //    sort(nums.begin(), nums.end());
     //    for(int i = 0;i<n-1; i++){
     //        diff = max(diff, nums[i+1]-nums[i]);
     //    }
     //    return diff;
        
    
     //O(n) approach
      int maxNum = INT_MIN, minNum = INT_MAX ;  
        int n = nums.size();
        if(n<2)
            return 0;
        for(int i=0; i<n; i++)
            maxNum=max(maxNum, nums[i]);
        for(int i = 0; i<n; i++)
            minNum = min(minNum , nums[i]);
        //bucket size
        int b = max((maxNum - minNum )/(n-1),1);
        
        //number of buckets
        int numBuckets = (maxNum - minNum)/b + 1;
        
        //creating these buckets
        vector<pair<int,int>> buckets(numBuckets, make_pair(INT_MAX, INT_MIN)); // pair of for (min, max)
        
        
        //mapping numbers to these buckets
        
        for(int i =0; i<n; i++){
            int bnum = (nums[i]-minNum)/b;
            buckets[bnum].first = min(buckets[bnum].first, nums[i]);
            buckets[bnum].second = max(buckets[bnum].second, nums[i]);
            
        }
        
        //calculating the answer
        
        int res = 0;
        int prev = buckets[0].second;
        for(int i=1; i<numBuckets; i++)
        {
            //case of empty bucket
            if(buckets[i].first == INT_MAX && buckets[i].second == INT_MIN)
                continue;
            
            res = max(res, buckets[i].first-prev);
            prev = buckets[i].second;         
        }
        
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};