class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> words(nums.size());
        for(int i=0; i<nums.size(); i++)
            words[i] = to_string(nums[i]);
        sort(words.begin(), words.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string result;
        for(int i =0; i<words.size(); i++)
            result += words[i];
        
        while(result[0]=='0'&& result.length()>1)
        {
            result.erase(0,1);
        }
    
    return result;
    
    }
    
};