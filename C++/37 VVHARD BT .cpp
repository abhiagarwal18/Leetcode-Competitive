class Solution {
public:
    void f(vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &box, int rowId, int colId, vector<<vector<char>> &currboard, vector<vector<char>> &res ){
        //subprob dont need the whole board, only row bool, col bool and box no. bool
        //contribution through currboard situation 
        //res as the final board
        //rowId and colId for the startIdx
         
        //positive base case
        
        if(rowId ==9  )
        {res = currboard;
        return;}
        
        //recursive case
        
        //if non empty cell
        if(currboard[rowId][colId] != '.'){
             if(colId == 8)
                    f(row, col, box, rowId+1,0, currboard, res );
                else
                    f(row, col, box, rowId, colId+1, currboard, res);
            return; // VERY VERY IMP TO ADD RETURN ELSE MIGHT GO TO THE NEXT LOOP
         }
        
        //assuming that this is an empty cell
        int i ;
        for(i =1 ; i<=9; i++){
            if(!row[rowId][i-1] && !col[colId][i-1] && !box[3*(rowId%3) + colId%3][i-1]){ //checking if have i in the row/col/box
                currboard[rowId][colId] = (char)('0' + i);
                row[rowId][i-1] = true;
                col[colId][i-1] = true;
                box[3*(rowId/3) + colId/3][i-1] = true; //since traversing from left to right and top to bottom
                if(colId == 8)
                    f(row, col, box, rowId+1,0, currboard, res );
                else
                    f(row, col, box, rowId, colId+1, currboard, res);
                currboard[rowId][colId] = '.';
                row[rowId][i-1] = false;
                col[colId][i-1] = false;
                box[3*(rowId/3) + colId/3][i-1] = false;
            }
        }
        
        
    }
    void solveSudoku(vector<vector<char>>& board) {
         vector<vector<bool>>row(9, vector<bool>(9,false));
         vector<vector<bool>>col(9, vector<bool>(9,false));
         vector<vector<bool>>box(9, vector<bool>(9,false));
        int i , j ;
        for( i  = 0; i<9; i++){
            for(j=0; j<9; j++){
                if(board[i][j]!= '.')
                {
                row[i][(board[i][j]-'0')-1] = true;
                col[i][(board[i][j]-'0')-1]= true;
                box[3*(rowId/3) + colId/3][(board[i][j]-'0')-1] = true;
                }
            }
        }
        vector<vector<char>>currboard = board;
        vector<vector<char>>res = board;
        f(row, col, box, 0, 0, currboard, res );
        
    }
};