class Solution {
public:
    
    bool isSub(string temp, string s){
        
        int i = 0, j = 0;
        for(int i = 0; i< s.length(); i++){
            if(s[i]== temp[j])
                j++;
            if(j== temp.length())
            return true;
        }
        
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        sort(d.begin(), d.end());
        for(int i = 0; i<d.size(); i++){
            string temp = d[i];
            if(temp.length() <= ans.length())
                continue;
            if(isSub(temp, s) == true)
                ans = temp;
        }
        return ans;
    }
};