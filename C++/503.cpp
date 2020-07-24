class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        vector<int> res(n, -1);
        
        //follow the monotonically decreasing property of the stacks
        //and go element wise
        
        for(int i = 0; i<2*n; i++){
            int index = i%n; 
            while(!stk.empty()&& nums[stk.top()]<nums[index]){ //we are storring indices instead of elements of the array since there can be duplicates
                    res[stk.top()] = nums[index];
                    stk.pop();}
        
            stk.push(index);
        }

    return res;
    }
};