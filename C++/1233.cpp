class Solution {
public:
    bool checkSub(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        int act = min(n,m);
        for(int i =0 ; i<act; i++)
            if(s1[i] != s2[i])
                return false;
        if(n>act && s1[act] != '/')
            return false;
        if(m>act && s2[act]!= '/')
            return false;
        return true;
        
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        int i =0;
        bool substr = false;
        vector<string>res;
        while(i<n){
            res.push_back(folder[i]);
            
            int j = i+1;
            
            while(j<n)
            {
                substr = checkSub(folder[i], folder[j]);
                if(substr==false)// if its true then that means that its a subsrting and we need to check further
                    break;
                j++;
            }
            i = j;
        }
        return res;
    }
};