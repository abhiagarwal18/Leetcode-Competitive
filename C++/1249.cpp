class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int>stk;
        for(int i = 0; i<s.size(); i++){
            if(s[i]== '(' ){
                if(!stk.empty() && s[stk.top()]=='(')
                    stk.push(i);
                 else
                     stk.push(i);
            }
            else if(s[i]==')')
            {
                if(!stk.empty() && s[stk.top()] == '(')
                    stk.pop();
                else
                     stk.push(i);
            }
        }
        
     
stack < int > temp;
        while(!stk.empty())
        {
            temp.push(stk.top());
            cout << temp.top() << " ";
            stk.pop();
        }
        string ans="";
        for(int i=0;i<s.size(); i++)
        {
            if(!temp.empty() && temp.top()==i) temp.pop();
            else ans+=s[i];
            
        }
        return ans;}
    
    
};





// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         int n=s.size();
//         stack < int > stk;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='(' || s[i]==')')
//             {
//                 if(stk.empty()) stk.push(i);
//                 else if(s[i]=='(') stk.push(i);
//                 else if(!stk.empty() && s[stk.top()]=='(' && s[i]==')') stk.pop();
//                 else if(s[i]==')') stk.push(i);
//             }
//             else
//                 continue;
//         }
//         stack < int > temp;
//         while(!stk.empty())
//         {
//             temp.push(stk.top());
//             cout << temp.top() << " ";
//             stk.pop();
//         }
//         string ans="";
//         for(int i=0;i<n;i++)
//         {
//             if(!temp.empty() && temp.top()==i) temp.pop();
//             else ans+=s[i];
            
//         }
//         return ans;}
// };