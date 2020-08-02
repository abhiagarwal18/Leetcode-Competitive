class Solution {
public:
    //palindrome checker function
    bool palindromeCheck(string s){
        int i = 0; 
        int j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
            
        }
        return true;
    }
    //decision : starting with each index, add a character and push to currset if a palindrome
    void f(string &s, int startIdx, vector<vector<string>>&res, vector<string>currset ){
        //base case
        //when all indices covered
        if(s.length() == startIdx){
            res.push_back(currset);
            return ;
        }
        //recursive case
        string temp = "";
        for(int i = startIdx; i<s.length(); i++){
            temp+= s[i];
            if(palindromeCheck(temp)){
                currset.push_back(temp);
                f(s, i+1, res, currset);
                currset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>currset;
        f(s, 0, res, currset);
        return res;
    }
};