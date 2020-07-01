class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int smallerarray = nums1.size()<nums2.size() ? 1 : 2;
        if(smallerarray == 1){
            for(int i = 0; i<nums1.size(); i++){
                if(find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()){
                    if(find(res.begin(), res.end(), nums1[i]) != res.end())
                        continue;
                    else
                    res.push_back(nums1[i]);
                }
            }
        }
        else{
            for(int i = 0; i<nums2.size(); i++){
                if(find(nums1.begin(), nums1.end(), nums2[i]) != nums1.end()){
                    if(find(res.begin(), res.end(), nums2[i]) != res.end())
                        continue;
                    else
                    res.push_back(nums2[i]);
                }
            }
        }
        return res;
    }
};