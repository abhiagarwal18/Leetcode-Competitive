class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int l =0, r= 0;
        int res = INT_MIN;
        map<int,int> ref;
        while(r<n){
            ref[tree[r]]++;
            if(ref.size()>2){
                while(ref.size()>2){
                    ref[tree[l]]--;
                    if(ref[tree[l]] <= 0)
                        ref.erase(tree[l]);
                    l++;
                }
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};