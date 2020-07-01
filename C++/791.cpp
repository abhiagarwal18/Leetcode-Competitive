string temp;

bool comp(char&a, char &b)
{
    return temp.find(a)< temp.find(b);
}






class Solution {
public:
    string customSortString(string S, string T) {
        temp = S;
        sort(T.begin(), T.end(), comp);
        // if write as a lambda functions  : 
        // sort(T.begin(), T.end(), [](char &a, char &b){
        //     return S.find(a)>S.find(b);
        // })
        return T;
    }
};