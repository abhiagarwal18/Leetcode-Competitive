class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size(),currarea,maxarea=0,k;
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            vector <int> heights(m,0),smallestrght(m,0),smallestleft(m,0);
            k=i;
            for(int j=0;j<m;j++){
                while(matrix[i][j]!='0'){
                    heights[j]+=1;
                    i--;
                    if(i==-1) break;
                }
                i=k;
            }
            for(int j=0;j<m;j++){
            while(!stk.empty()&&heights[j]<heights[stk.top()]){
                smallestleft[stk.top()]=j;
                stk.pop();
            }
            stk.push(j);
        }
        while(!stk.empty()){
            smallestleft[stk.top()]=m;
            stk.pop();
        }
        for(int j=m-1;j>=0;j--){
            while(!stk.empty()&&heights[j]<heights[stk.top()]){
                smallestrght[stk.top()]=j;
                stk.pop();
            }
            stk.push(j);
        }
        while(!stk.empty()){
            smallestrght[stk.top()]=-1;
            stk.pop();
        }
            for(int j=0;j<m;j++){
                currarea=((smallestleft[j]-1)-(smallestrght[j]+1)+1)*heights[j];
                if(currarea>maxarea) maxarea=currarea;
            }
        }
        return maxarea;
    }
};