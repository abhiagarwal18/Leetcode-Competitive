class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> temp;
        for(int i =0; i<restaurants.size(); i++){
            if(veganFriendly == 1){
                if(restaurants[i][2] == 1 && restaurants[i][3] <= maxPrice && restaurants[i][4]<= maxDistance)
                    temp.push_back(restaurants[i]);}
            else{
                if(restaurants[i][3] <= maxPrice && restaurants[i][4]<= maxDistance)
                    temp.push_back(restaurants[i]);}
            
        }
        
        sort(temp.begin(), temp.end(), [=](vector<int>a, vector<int>b){
            if(a[1]!=b[1])
                return a[1]>b[1];
            else
                return a[0]>b[0];
            
        });
            
        vector<int>ans;
        for(int i=0; i<temp.size(); i++)
            ans.push_back(temp[i][0]);
        
        return ans;
        
    }
};