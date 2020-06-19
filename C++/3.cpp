class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        int l = 0, r= 0;
        int res = INT_MIN;
       map<char,int>ref;
        while(r<n){
            ref[s[r]]++;
            cout<<s[r]<<" freq "<< ref[s[r]]<<endl;
            if(ref[s[r]]>1){
                cout<<"in if ";
                while(ref[s[r]]>1){
                    cout<<"in while ";
                    ref[s[l]]--;
                    l++;
                    if(ref[s[l]]==0)
                        ref.erase(s[l]);
                }
                
                }
            cout<<"r "<<r<<"l "<<l<<endl;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};