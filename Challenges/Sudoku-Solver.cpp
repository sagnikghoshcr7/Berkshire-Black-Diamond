/*
Problem : Sudoku Solver
Problem Link : https://leetcode.com/problems/sudoku-solver/


*/

class Solution {
public:
    
    
    
    bool check(vector<vector<char>>& board,int i, int j,char op)
    {
        
        for(int k=0;k<9;k++){
            
            if( board[i][k]==op) return false;
        }
        for(int k=0;k<9;k++){
            
            if( board[k][j]==op) return false;
        }
        int x = i/3;
        int y = j/3;
        for(int p=0; p<3;p++){
            for(int q=0;q<3;q++){
                if(board[3*x+p][3*y+q]==op) return false;
            }
        }
        
        return true;
    }
    
    
    
    vector<vector<char>>v ;
    bool sudoku(vector<vector<char>>& board,int i, int j){
        
        if(j==9){
            i+=1;
            j=0;
        }
        if(i==9){
            return true;
        }
      
     if(board[i][j]=='.'){
         
         for(char k='1';k<='9';k++)
         if(check(board,i,j,k)){
             board[i][j] = k;
             if(sudoku(board,i,j+1)==true)return true;
             else{
               board[i][j] = '.';   
             }
         }
         
     }
        else{
            return sudoku(board,i,j+1);
        }
        
        return false;
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
       sudoku(board,0,0);
            
    }
};