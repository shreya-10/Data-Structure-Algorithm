import java.util.ArrayList;
class permutation
{
    //return type
   public static ArrayList<String> permu(String str)
   {
       if(str.length()==1)
       {
           ArrayList<String> base=new ArrayList<>();
           base.add(str);
           return base;
       }
       char ch=str.charAt(0);
       String ros=str.substring(1);
       ArrayList<String> ans=permu(ros);
       ArrayList<String> myans=new ArrayList<>();
       for(String s:ans)
       {
           for(int i=0;i<=s.length();i++)
           {
               myans.add(s.substring(0,i)+ch+s.substring(i));
           }
       }

  return myans;

   }

   public static void permu_void(String ques,String ans)
   {
       if(ques.length()==0)
       {
           System.out.print(ans+ " ");
           return;
       }

        for(int i=0;i<ques.length();i++)
        {
            char ch=ques.charAt(i);
            String roq=ques.substring(0,i)+ques.substring(i+1);
            permu_void(roq,ans+ch);
        }
        return;
   }
   public static void permu_woDuplicacy(String ques,String ans)
   {
       if(ques.length()==0)
       {
           System.out.print(ans+ " ");
           return;
       }
       boolean vis[]=new boolean[26];
        for(int i=0;i<ques.length();i++)
        {
       char ch=ques.charAt(i);
            
        if(!vis[ch-'a'])
        {   vis[ch-'a']=true;
            String roq=ques.substring(0,i)+ques.substring(i+1);
            permu_woDuplicacy(roq,ans+ch);
        }
        }
        return;
   }

   public static void main(String args[])
   {
    //   
    //permu_void("abc","");
    permu_woDuplicacy("aba","");
   }

}