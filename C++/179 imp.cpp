class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        
        //creating a vector of strings
        for(int i=0; i<nums.size(); i++){
            temp.push_back(to_string(nums[i]));
        }
              
        //sorting the vector of strings
        
        sort(temp.begin(), temp.end(),[=](string &a, string &b){
            string s1 = a+b;
            string s2 = b+a;
            if(s1>s2)
                return 1;
            else 
                return 0;
            }
        );
        
        string ans= "";
        for(int i=0; i<temp.size(); i++)
            ans += temp[i];
        
        //clearing initial zeroes
        
        while(ans.size()>1 && ans[0]=='0'){
            ans.erase(ans.begin());
        }
        
        return ans;
        
        
        
        
    }
};