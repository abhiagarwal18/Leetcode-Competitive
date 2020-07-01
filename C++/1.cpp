class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> temp;
        vector<int> res;
        for(int i =0; i<n; i++){
            if(temp.find(target-nums[i]) != temp.end()){
                //element found means push back to result and return 
                res.push_back(i);
                res.push_back(temp[target-nums[i]]);
                return res;
            }
            else
                temp[nums[i]] = i;
                
        }
        
        return res;
        
    }
};