class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int p1=0, p2=n-1;
        int res = 0, area = 0;
        while(p2>p1){
            area= (p2-p1)*min(height[p1], height[p2]);
            res = max(area, res);
            (height[p1]>=height[p2])? (p2--) : p1++;
        }
        return res;
    }
};