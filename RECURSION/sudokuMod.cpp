
#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>>& grid)  
{  
    for (int row = 0; row < 9; row++)  
    {  
    for (int col = 0; col < 9; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  



int sudoku(vector<vector<int>> &board ,vector<int>& calls,int idx,vector<int>& row,vector<int>& col,vector<vector<int>>& mat)
{
    if(idx==calls.size())
    {
        display(board);
     return 1;
    }

    int count =0;
    int x=calls[idx]/9;
    int y=calls[idx]%9;
    
        for(int num=1;num<=9;num++)
        {
            int mask=1<<num;
            if((row[x]&mask)==0  && (col[y]&mask)==0 && (mat[x/3][y/3]&mask)==0)  
            {
            row[x]^=mask;
            col[y]^=mask;
            mat[x/3][y/3]^=mask;
            board[x][y]=num;
            count+=sudoku(board,calls,idx+1,row,col,mat);
            board[x][y]=0;
            row[x]^=mask;
            col[y]^=mask;
            mat[x/3][y/3]^=mask;
            }
           
        }
          return count;

    }


 
   
   
   int main(int arg,char** b)  
{  
  
    vector<vector<int>> grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    vector<int> calls;
    vector<int> row(9);
    vector<int> col(9);
    vector<vector<int>> mat(3,vector<int>(3));

    for (int i = 0; i < 9; i++)  
        {  
        for (int j = 0; j < 9; j++)  
                {
                    if(grid[i][j]==0)
                    {
                        calls.push_back((i*9+j));
                    }
                    else
                    {
                    int num=grid[i][j];
                    int mask=1<<num;
                    row[i]=row[i]|mask;
                    col[j]|=mask;
                    mat[i/3][j/3]|=mask;
                    }
                }
           
        }  
                      cout<<endl<<sudoku(grid,calls,0,row,col,mat)<<endl;
                     
}


//LEETCODE  37.
class Solution {
public:
    void display(vector<vector<char>>& grid)  
{  
    for (int row = 0; row < 9; row++)  
    {  
    for (int col = 0; col < 9; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  
    
bool sudoku(vector<vector<char>> &board ,vector<int>& calls,int idx,vector<int>& row,vector<int>& col,vector<vector<int>>& mat)
{
    if(idx==calls.size())
    {
        display(board);
     return true;
    }

    int count =0;
    int x=calls[idx]/9;
    int y=calls[idx]%9;
    bool res=false;
        for(int num=1;num<=9;num++)
        {
            int mask=1<<(num);
            if((row[x]&mask)==0  && (col[y]&mask)==0 && (mat[x/3][y/3]&mask)==0)  
            {
            row[x]^=mask;
            col[y]^=mask;
            mat[x/3][y/3]^=mask;
            board[x][y]=(char)(num+'0');
            if(sudoku(board,calls,idx+1,row,col,mat))return true;
            board[x][y]='.';
            row[x]^=mask;
            col[y]^=mask;
            mat[x/3][y/3]^=mask;
            }
           
        }
          return count;

    }


 
    void solveSudoku(vector<vector<char>>& board) {
         vector<int> calls;
    vector<int> row(9);
    vector<int> col(9);
    vector<vector<int>> mat(3,vector<int>(3));

    for (int i = 0; i < 9; i++)  
        {  
        for (int j = 0; j < 9; j++)  
                {
                    if(board[i][j]=='.')
                    {
                        calls.push_back((i*9+j));
                    }
                    else
                    {
                    int num=board[i][j];
                    int mask=1<<(num-'0');
                    row[i]=row[i]|mask;
                    col[j]|=mask;
                    mat[i/3][j/3]|=mask;
                    }
                }
           
        }
        bool a=sudoku(board ,calls,0,row,col,mat);
        
                     
    }
};



//LEETCODE 36.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> row(9);
    vector<int> col(9);
    vector<vector<int>> mat(3,vector<int>(3));

    for (int i = 0; i < 9; i++)  
        {  
        for (int j = 0; j < 9; j++)  
                {
                    if(board[i][j]!='.')
                    {
                        
                    int num=board[i][j];
                    int mask=1<<(num-'0');
                    if((row[i]&mask)==0  && (col[j]&mask)==0 && (mat[i/3]                                  [j/3]&mask)==0)
                    {
                    row[i]=row[i]|mask;
                    col[j]|=mask;
                    mat[i/3][j/3]|=mask;
                    }
                        else
                            return false;
                    }
                }
           
        }  
        return true;
    }
};


