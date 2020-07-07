class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
      vector<int>temp=A;vector<int>result;
      sort(temp.begin(),temp.end(),greater<int>());
      for(int i=0;i<temp.size();i++)
      {
          if(A[A.size()-i-1]==temp[i]) continue;//Already Sorted
          int j;
          for(j=0;j<(A.size()-i);j++)
          {
              if(temp[i]==A[j]) break;
          }
          if(j!=0)
          {
               result.push_back(j+1);
               result.push_back(A.size()-i);
          }
          else result.push_back(A.size()-i);
          reverse(A.begin(),A.begin()+j+1);
          reverse(A.begin(),A.begin()+A.size()-i);
      }
      return result;
    }
};