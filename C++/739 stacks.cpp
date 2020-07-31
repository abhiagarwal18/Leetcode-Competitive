class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //run one for each element from the end 
        //create a stack with corresponding temperature indices and 
        //for each run create a stack and add the corresponding elements then add until a greater is reached
        
        vector<int> ans(T.size(), -1);
        stack<int> stk;
        for(int i=T.size()-1; i>=0; i--){
            while(!stk.empty() && T[i]>=T[stk.top()])
                stk.pop();
            ans[i] = stk.empty() ? 0 : (stk.top() - i);
            stk.push(i);
        }
        return ans;
        
        
        
    }
};