class Solution {
public:
    void solve(vector<int>& candidates,int si,int target,vector<vector<int>>& res,vector<int> curset)
    {
        int n=candidates.size();
        if(target==0)
        {
            res.push_back(curset);
            return;
        }
        if(si==n)
        {
            return;
        }
        int i = si;
        while(i<n)
        {  
            if(candidates[i]>target)
                break;
            if(i==si || candidates[i]!=candidates[i-1])
            {
                curset.push_back(candidates[i]);
                solve(candidates,i+1,target-candidates[i],res,curset);
                curset.pop_back();
            }
            i++;
                    
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curset;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,res,curset);
        return res;
        
    }
};