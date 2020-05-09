import java .util.ArrayList;
import java.util.Scanner;
class stairPath
{

    public static ArrayList<String> stair_01(int dest)
    {
        if(dest==0)
        {
            ArrayList<String> base=new ArrayList<String>();
            base.add("");
            return base;
        }
        ArrayList<String> stod=new ArrayList<String>();
         
        for(int i=1;i<=3;i++)
        {
            if(dest-i>=0)
            {
         ArrayList<String> nbrtod=stair_01(dest-i);
        for(String s:nbrtod)
        {
            stod.add(i+s+"");
        }
            }
        }
        
        
return stod;
    }

    public static int stair_02(int dest,String ans)
    {
        if(dest==0)
        {
             System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int step=1;step<=3;step++)
        {
            if(dest-step>=0)
            count +=stair_02(dest-step,ans+step+"");
        }
        return count;
    }


        public static void main(String args[])
        {
            Scanner scn=new Scanner(System.in);
            int dest=scn.nextInt();
            //System.out.println(stair_01(dest));
            System.out.println(stair_02(dest,""));
        }
}