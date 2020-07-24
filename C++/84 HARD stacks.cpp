class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //one array for all the left NSE
        //one array for all the right NSE
        //one run for max area
        int n = heights.size();
        if(n==0)
            return 0;
        vector<int> l_nse(n,-1); //indices
        vector<int> r_nse(n,n);
        stack<int> stk;
        
        //run for right NSE
        for(int i = 0; i<n ; i++){
            while(!stk.empty() && heights[stk.top()]> heights[i])
            {
                r_nse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        //empty the same stack for reuse
        while(!stk.empty())
            stk.pop();
        
        //run for l_nse
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()]>heights[i])
            {
                l_nse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        //final run for area calculation
        
        //right_min[i] - left_min[i] - 1 --> this number of bars
            //excluding last and first
        int area = INT_MIN;
        for(int i =0; i<n; i++)
            area = max(area, (heights[i]* (r_nse[i]-l_nse[i]-1)));
        return area;
        
        
    }
};