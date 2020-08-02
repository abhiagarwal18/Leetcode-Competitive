class Solution {
public:
    //decision : if next alphabet of the word lies to l/r/u/d continue
    bool f(vector<vector<char>>& board, string &word, int curridxinword,vector<vector<bool>>&visited, int currrow, int currcol ){
        int rows= board.size(); 
        int cols = board[0].size();
        int n = word.length();
        //base case
        if(n==curridxinword)
            return true;
        //corner cases
        if(currcol<0 or currcol>cols-1 or currrow<0 or currrow>rows-1)
            return false;
        //recursive case
        //only unvisited characters to be checked
        if(!visited[currrow][currcol] && board[currrow][currcol] == word[curridxinword]){
            
            //mark it visited and continue, and finally mark it false back
            visited[currrow][currcol] = true;
            //could be found in up, down, left, right
            if(f(board, word, curridxinword+1, visited, currrow-1, currcol))
                return true;//up
            else if(f(board, word, curridxinword+1, visited, currrow+1, currcol))
                return true;//down
            else if(f(board, word, curridxinword+1, visited, currrow, currcol+1))
                return true;//right
            else if(f(board, word, curridxinword+1, visited, currrow, currcol-1))
                return true;//left
            //unmark
            visited[currrow][currcol] = false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int n = word.length();
        int r, c;
        //to store visited positions :
        vector<vector<bool>>visited(rows,vector<bool>(cols, false));
        
        //search for the first occurance of the alphabet of the string
        for(r=0; r<rows; r++){
            for(c=0; c<cols; c++){
                if(board[r][c] == word[0] && !visited[r][c]){
                    //solve with this being the starting point
                    if( f(board, word, 0,visited, r, c )) return true;
                }
            }
        }
        //else 
        return false;
    }
};