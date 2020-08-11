class Solution {
public:
    void handleAfterDec(long long int n , long long int d, string &res){
        
        //print part afoter decimal
        // plan : keep printing till i get a repetition
        //once i get it, come back and insert opening bracket and closing one
        //lets track the numerator : if get the same then the pattern will repeat
        //to go back to starting index of pattern store its index in the map
        unordered_map<long long int, long long int>m;
        long long int q;
        while(n>0){
                    n = n*10;

            while(n*10 < d){
            res += "0";
             n = n*10;
        }//doing while n<d add 0s
            //in loop since eg 130/129 --- 1.0077...
            //appended two zeros since multiplied 1 ie remainder with 1000
            //append zeroes till n*10 < denominator
            if(m.find(n) != m.end())
                break;
            q = n/d;
            
            m[n] = res.size(); //pattern stored 
            
            res += to_string(q);

            n = n%d;
            
        }
        if(n==0 ) return ;
        
        //insert bracket
        string prefix = res.substr(0, m[n]); //starting position and length
        string suffix = res.substr(m[n], res.size()-m[n]);
        res = prefix + "(" + suffix + ")";
        return ;
        
        
        
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        //find the part before the decimal
        //handle negatives
        string res = "";
        long long int n = numerator, d= denominator;
        if(n==0) return "0";
        
        if( (n<0 && d>0) ||(n>0 && d<0)){ //num*den<0 not right as it might overflow
            res+='-';
      }
        
        n = abs(n);
        d = abs(d);
        //good for positives
        //part before decimal
        res += to_string(n/d);
        long long int rem;
     rem = n%d;
        if(rem == 0 ) return res;
        //add decimal point
        res += ".";
        //handle part after decimal
        handleAfterDec(rem,d,res);
        return res;
    }
};