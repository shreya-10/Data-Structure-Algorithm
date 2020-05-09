class coinchange
{
   public static int coinpemuInfy(int coins[],int tar,String ans)
   {
       if(tar==0)
       {
           System.out.print(ans+"  ");
           return 1;
       }

        int count=0;
       for(int i=0;i<coins.length;i++)
       {
            if(tar-coins[i]>=0)
            count+=coinpemuInfy(coins,tar-coins[i],ans+coins[i]+"");   
       }
       return count;
   }

    public static int coincombiInfy(int coins[],int tar,int idx,String ans)
   {
       if(tar==0)
       {
           System.out.print(ans+"  ");
           return 1;
       }

        int count=0;
       for(int i=idx;i<coins.length;i++)
       {
            if(tar-coins[i]>=0)
            count+=coincombiInfy(coins,tar-coins[i],i,ans+coins[i]+"");   
       }
       return count;
}

  public static int coincombiSingle(int coins[],int tar,int idx,String ans)
   {
       if(tar==0)
       {
           System.out.print(ans+"  ");
           return 1;
       }

        int count=0;
       for(int i=idx;i<coins.length;i++)
       {
            if(tar-coins[i]>=0)
            count+=coincombiSingle(coins,tar-coins[i],i+1,ans+coins[i]+"");   
       }
       return count;
   }

    public static int coinpermuSingle(int coins[],int tar,String ans,boolean[]  vis)
   {
       if(tar==0)
       {
           System.out.print(ans+"  ");
           return 1;
       }

        int count=0;
       for(int i=0;i<coins.length;i++)
       {
            if(tar-coins[i]>=0 && !vis[i])
            {
            vis[i]=true;
            count+=coinpermuSingle(coins,tar-coins[i],ans+coins[i]+"",vis);
            vis[i]=false;
            }   
       }
       return count;
   }


   //SUBSEQUENCE
 public static int coinpemuInfy_02(int coins[],int tar,int idx,String ans)
   {
       if(idx==coins.length || tar==0)
       {
           if(tar==0)
           {
           System.out.print(ans+" ");
           return 1;
           }
           return 0;
       }
int count=0;
       if(tar-coins[idx]>=0)
       count+=coinpemuInfy_02(coins,tar-coins[idx],0,ans+coins[idx]+"");

       count+=coinpemuInfy_02(coins,tar,idx+1,ans);
       return count;

   }

 public static int coincombiInfy_02(int coins[],int tar,int idx,String ans)
   {
       if(idx==coins.length || tar==0)
       {
           if(tar==0)
           {
           System.out.print(ans+" ");
           return 1;
           }
           return 0;
       }
int count=0;
       if(tar-coins[idx]>=0)
       count+=coincombiInfy_02(coins,tar-coins[idx],idx,ans+coins[idx]+"");

       count+=coincombiInfy_02(coins,tar,idx+1,ans);
       return count;

   }
 public static int coincombiSingle_02(int coins[],int tar,int idx,String ans)
   {
       if(idx==coins.length || tar==0)
       {
           if(tar==0)
           {
           System.out.print(ans+" ");
           return 1;
           }
           return 0;
       }
int count=0;
       if(tar-coins[idx]>=0)
       count+=coincombiSingle_02(coins,tar-coins[idx],idx+1,ans+coins[idx]+"");

       count+=coincombiSingle_02(coins,tar,idx+1,ans);
       return count;
   }
   public static int coinpermuSingle_02(int coins[],int tar,int idx,String ans,boolean vis[])
   {
       if(idx==coins.length || tar==0)
       {
           if(tar==0)
           {
           System.out.print(ans+" ");
           return 1;
           }
           return 0;
       }
int count=0;
       if(tar-coins[idx]>=0 && !vis[idx])
       {
           vis[idx]=true;
       count+=coinpermuSingle_02(coins,tar-coins[idx],0,ans+coins[idx]+"",vis);
       vis[idx]=false;
       }

       count+=coinpermuSingle_02(coins,tar,idx+1,ans,vis);
       return count;

   }
   public static void main(String args[])
   {
       int coins[]={2,3,5,7};
       boolean vis[]=new boolean[coins.length];
    //   System.out.println(coinpemuInfy(coins,10,""));
     // System.out.println(coincombiInfy(coins,10,0,""));
       //System.out.println(coincombiSingle(coins,10,0,""));

    System.out.println(coinpermuSingle(coins,10,"",vis));

      //SUBSEQUENCE
      // System.out.println(coinpemuInfy_02(coins,10,0,""));
     // System.out.println(coincombiInfy_02(coins,10,0,""));
      //System.out.println(coincombiSingle_02(coins,10,0,""));
       System.out.println(coinpermuSingle_02(coins,10,0,"",vis));

   }
}