public class knightstour
{
   static int counter=0;
    public static void knights(int[][] board,int row,int col,int move)
    {
        if(row<0 || col<0
            || row>=board.length || col>=board[0].length ||
            board[row][col]!=0)
            return;
        else if(move==board.length*board[0].length)
       {
           counter=counter+1;
           System.out.println("***********************"+counter+"*****************************");
          board[row][col]=move;
          for(int i=0;i<board.length;i++)
          {
          for(int j=0;j<board[0].length;j++)
          {
              System.out.print(board[i][j]+"\t");
          }
          System.out.println();
          }

         board[row][col]=0;
       }
       board[row][col]=move;
       knights(board,row-1,col+2,move+1);
       knights(board,row-1,col-2,move+1);
       knights(board,row+1,col+2,move+1);
       knights(board,row+1,col-2,move+1);
       knights(board,row-2,col-1,move+1);
       knights(board,row-2,col+1,move+1);
       knights(board,row+2,col-1,move+1);
       knights(board,row+2,col+1,move+1);
       board[row][col]=0;

    }
    public static void main(String args[])
    {
        int board[][]=new int[5][5];
        knights(board,1,3,1);

    }
     
}