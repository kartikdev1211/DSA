#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<vector<char>>&board,int value){
    int n=board.size();
    for(int i=0;i<n;i++){
        if(board[row][i]==value){
            return false;
        }
        if(board[i][col]==value){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>&board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        bool nextSolutionPoss=solve(board);
                        if(nextSolutionPoss){
                            return true;
                        }else{
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>&sudoku){
    solve(sudoku);
}