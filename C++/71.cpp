class Solution {
public:
    string simplifyPath(string path) {
        string tmp ;
        stack<string> stk ;
        stringstream ss(path); //USED TO APPLY SPECIAL FUNCTIONS LIKE GETLINE ON STRINGS
        while(getline(ss, tmp, '/')){ 
            //GETLINE USED TO SPLIT ACC TO FORMAT GETLINE ( STRINGSTREAM, STORAGE STRING, DELIMITER) STEP BY STEP
            if(tmp == "" || tmp ==".") continue;
            if(tmp == ".." && !stk.empty()) stk.pop();
            else if(tmp!= "..") stk.push(tmp);
            
        }
        //now add the stack results to hte resultant string
        string res="";
        while(!stk.empty())
        {res = '/'+stk.top() +res;
         stk.pop();}
        return res=="" ? "/" : res; //return / if res is an empty string
        
    }
};