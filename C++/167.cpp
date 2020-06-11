class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), p1= 0, p2=n-1;
        vector<int>res;
        while(p1<=p2){
            if(numbers[p1]+numbers[p2]==target)
            {
                res.push_back(p1+1);
                res.push_back(p2+1);
                break;
            }
            else if(numbers[p1]+numbers[p2]<target)
                p1++;
            else
                p2--;
        }
        return res;
    }
};