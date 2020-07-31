class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int rows = a.size();
        if (rows == 0) {
            return {};
        }
        int cols = a[0].size();
        vector<int>res;
        int fr = 0, lr = rows-1, fc = 0, lc = cols-1;
        while(fr <= lr and fc <= lc) {
            for (int i = fc; i<=lc; i++) {
                res.push_back(a[fr][i]);
            }
            fr++;
            if (lc >= fc) {
                for (int i = fr; i<= lr; i++) {
                    res.push_back(a[i][lc]);
                }
                lc--;
            }
            
            
            if (lr >= fr) {
                for (int i = lc; i>= fc; i--) {
                    res.push_back(a[lr][i]);
                }
                lr--;
            }
            
            
            if (fc <= lc)
                {for (int i = lr; i>=fr; i--) {
                    res.push_back(a[i][fc]);
                }
                fc++;
            }
        }
        return res;
    }
};