class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        
      //  if(n==k) return "0";
        /*
        string ans = "";
        
        for(char c: num){
            
            while(ans.size() && ans.back() > c && k){
                ans.pop_back();
                k--;
            }
            if(ans.length() || c!='0') ans.push_back(c);
        }
        
        while(k && ans.size()){
            ans.pop_back();
            k--;
        }
        
        return ans.empty()? "0" : ans;*/
        
        if(n==k )
            return "0";
        
        stack<int>stk;
        string res ="";
        
        for(int i=0; i<n; i++){
            while(!stk.empty() &&  nums[stk.top()] > nums[i] && k>0){
                stk.pop();
                k--;
            }
            if(!stk.empty() || nums[i]!= '0') // for leading zeros
                stk.push(i);
        }
        
        //for the case when k > 0 still
        while(k>0 && !stk.empty())
        {
            stk.pop();
            k--;
        }
        
        while(!stk.empty()){
            res = nums[stk.top()] + res;
            stk.pop();
        }
        return res.size()==0 ? "0" : res;
            
        
        
        
        
        
        
        
        
        
    }
};