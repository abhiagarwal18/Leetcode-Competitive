class Solution {
public:
    int numRabbits(vector<int>& answers) {
    //storing the counts
        //use a hashtable unordered map with key as the reporting and value as teh count
        int n = answers.size();
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++){
            m[answers[i]]++;
        }//grouping of the rabbits giving the same number as the answer : storing the frequencies of each answer
        // if use .find() then the iterator could be declared with datatype as auto to avoid confusion
      
        //iterate over the map
        int key, value;
        int groups;
        int res = 0;
        for(auto it = m.begin(); it!=m.end(); ++it ){
            key = it->first;
            value = it->second;
            groups = ceil((float) value/(key+1));
            res+= groups*(key+1);
        }
        
        return res;
    }
};