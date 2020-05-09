import java .util.ArrayList;
class mazePath
{
    public static ArrayList<String> maze_01(int board[][],int i,int j)
    {
        if(i==board.length-1 && j==board[0].length-1)
        {
             ArrayList<String> base=new ArrayList<String>();
             base.add("");
             return base;
        }
        ArrayList<String> myans=new ArrayList<String>();
         if(j+1<board[0].length)
          {
               ArrayList<String> hans=maze_01(board,i,j+1);
               for(String s:hans)
                myans.add("H"+s);
          }
        if(i+1<board.length)
        {
           ArrayList<String> vans=maze_01(board,i+1,j);
           for(String s:vans)
           myans.add("V"+s);
        }
         return myans;


    }
    public static int maze_02(int board[][],int i,int j,String ans)
    {
        if(i==board.length-1 && j==board[0].length-1)
        {
            
             System.out.print(ans+"  ");
            return 1;
        }
        int count=0;
        if(j+1<board[0].length)
        count+=maze_02(board,i,j+1,ans+"H");
        if(i+1<board.length)
        count+=maze_02(board,i+1,j,ans+"V");
        return count;
    }
    public static ArrayList<String> maze_diag_01(int i,int j,int er,int ec)
    {
        if(i==er-1 && j==ec-1)
        {
             ArrayList<String> base=new ArrayList<String>();
             base.add("");
             return base;
        }
        ArrayList<String> myans=new ArrayList<String>();
         if(j+1<ec)
          {
               ArrayList<String> hans=maze_diag_01(i,j+1,er,ec);
               for(String s:hans)
                myans.add("H"+s);
          }
        if(i+1<er)
        {
           ArrayList<String> vans=maze_diag_01(i+1,j,er,ec);
           for(String s:vans)
           myans.add("V"+s);
        }
        if(j+1<ec && i+1<er)
        {ArrayList<String> dans=maze_diag_01(i+1,j+1,er,ec);
           for(String s:dans)
           myans.add("D"+s);

        }
         return myans;


    }
    public static int maze_diag_02(int i,int j,int er,int ec,String ans)
    {
        if(i==er-1 && j==ec-1)
        {
            
             System.out.print(ans+"  ");
            return 1;
        }
        int count=0;
        if(j+1<ec)
        count+=maze_diag_02(i,j+1,er,ec,ans+"H");
        if(i+1<er)
        count+=maze_diag_02(i+1,j,er,ec,ans+"V");
        if(j+1<ec && i+1<er)
        count+=maze_diag_02(i+1,j+1,er,ec,ans+"D");
        return count;
    }
      public static void main(String args[])
    {
        
        int board[][]=new int[4][4];
        // ArrayList<String> ans=maze_01(board,0,0);
        // System.out.println(ans);
        // System.out.println(ans.size());
        //System.out.println(maze_02(board,0,0,""));
        //System.out.println(maze_diag_01(0,0,3,3));
        System.out.println(maze_diag_02(0,0,3,3,""));

    }
}