class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>>v;
        int i,n = nums.size(), j, l;
        
        //form the tuples
        for(i =0; i<n; i++){
            if(i==0 || v[v.size()-1].first != nums[i])
                v.push_back(make_pair(nums[i],1));
            else 
                v[v.size()-1].second++;
        }
        
        //simulate
        for(i=0; i<v.size(); i++){
            if(v[i].second == 0) continue;
            
            // considering i, form buckets
            j=i;
            
            if(j+k-1>=n) 
                return false;
            
            for(l=j+1; l<j+k; l++){
                //this number should be consecutive to the prev number
                if(v[l].first != (v[l-1].first)+1) return false;
                
                //the count should be atleast count of j
                if(v[l].second < v[j].second) return false;
                
                v[l].second -= v[j].second;
            }
            
            
            
        }
        
        return true;
        
    }
};