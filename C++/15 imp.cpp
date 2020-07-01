class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int p1=0, p2=n-1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(nums[i] > 0)
                break;
            
            p1 = i+1;
            p2 = n-1;
            int target = -nums[i];
            while(p1 < p2){
                if(nums[p1]+nums[p2]== target){
                    vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[p1];
                triplet[2] = nums[p2];
                res.push_back(triplet);
                while (p1<p2 && nums[p1]==nums[p1+1] )
						p1+=1;
				while (p1<p2 && nums[p2]==nums[p2-1])
						p2-=1;
					p1+=1;
					p2-=1;
                }
                else if(nums[p1]+nums[p2] > target)
                    p2--;
                else if(nums[p1]+nums[p2]< target)
                    p1++;
                
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                    i++;
            
        }
        return res;
    }
};