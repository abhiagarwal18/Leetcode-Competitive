class Solution {
public:
   vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> res;
    for (int i : b)
        if (ctr[i]-- > 0)
            res.push_back(i);
    return res;
}};