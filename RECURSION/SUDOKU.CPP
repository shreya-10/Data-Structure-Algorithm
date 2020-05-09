#include<iostream>
#include<vector>
using namespace std;

bool isSafeToPlaceNumber(vector<vector<int>>& board,int row, int col,int num)
{
    for(int i=0;i<board.size();i++)
    {

        if(board[i][col]==num)
        return false;

    }
     for(int i=0;i<board[0].size();i++)
    {
        if(board[row][i]==num)
        return false;
        
    }

    int x=(row/3)*3;
    int y=(col/3)*3;

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        if(board[x+i][y+j]==num)
        return false;
    }
    return true;
}
void display(vector<vector<int>>& grid)  
{  
    for (int row = 0; row < 9; row++)  
    {  
    for (int col = 0; col < 9; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}  
int sudoku(vector<vector<int>> &board ,int idx)
{
    if(idx==81)
    {
        display(board);
     return 1;
    }

    int count =0;
    int row=idx/9;
    int col=idx%9;
    if(board[row][col]==0)
    {
        for(int num=1;num<=9;num++)
        {
            if(isSafeToPlaceNumber(board,row,col,num))
            {
            board[row][col]=num;
            count+=sudoku(board,idx+1);
            board[row][col]=0;
            }
        }

    }
    else
   count+=sudoku(board,idx+1);

   return count;
}

//to get only one ans and save other calls
bool sudoku_02(vector<vector<int>> &board ,int idx)
{
    if(idx==81)
    {
        display(board);
     return true;
    }

    int count =0;
    int row=idx/9;
    int col=idx%9;
    bool res= false;
    if(board[row][col]==0)
    {
        for(int num=1;num<=9;num++)
        {
            if(isSafeToPlaceNumber(board,row,col,num))
            {
            board[row][col]=num;
            res=res||sudoku_02(board,idx+1);
            board[row][col]=0;
            }
        }

    }
    else
   res=res||sudoku_02(board,idx+1);

   return res;
}
void solve(){
	int a;
	a=1;
	while(a<=1)
	if(a%2)
	cout<<a++<<"hi";
	else
	cout<<++a<<"hy";
	cout<<a+10<<"by";
}

int main(int arg,char** b)  
{  
    // 0 means unassigned cells  
    vector<vector<int>> grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
                    //   cout<<endl<<sudoku(grid,0)<<endl;
                    //   cout<<endl<<sudoku_02(grid,0)<<endl;
                    solve();
}

