//can array of size 256 for entire ascii and thus have the count of each char
// of of 52 since 26 capital 26 lower case
vector<int> freq(256,0);//global
bool comp(char &a, char&b){
    // return true if want a to be placed before b
    //f otherwise
    if(freq[a]==freq[b])
        return a<b; //IMPORTANT BECAUSE IF EG. (c,a,b) then should return same, not (a,b,c)
    return freq[a]>freq[b];
}


class Solution {
public:
    //sort(s.begin(),s.end(), comparator)
    // comparator should take two elements of the sequence
    // return type is bool
       string frequencySort(string s) {
            int n = s.size();
           fill(freq.begin(), freq.end(),0);
           int i;
           for(i=0; i<n; i++){
               freq[(int)s[i]]++;
           }
           sort(s.begin(), s.end(), comp);
           return s;
    }
};