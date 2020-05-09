import java.util.*;
class test
{

    public static void demo()
    {
         HashMap<String,Integer> map=new HashMap<>();
    map.put("usa",100);
    map.put("NZ",90);
    map.put("IND",100);
    map.put("ENG",70);
    map.put("SA",50);
    map.put("IND",200);
    for(String s:map.keySet())
    {
        System.out.print(s+"->"+map.get(s)+" ");
    }

    System.out.print("\n"+map);
    }


    public static void frequencyMap(String str)
    {   HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            // if(!map.containsKey(ch)) map.put(ch,1);
            // else
            // map.put(ch,map.get(ch)+1);
            map.put(ch,map.getOrDefault(ch,0)+1);
        }
         System.out.print(map);
    }

   public static void getIndex(String str)
   {
       HashMap<Character,ArrayList<Integer>> map=new HashMap<>();

       for(int i=0;i<str.length();i++)
       {
            char ch=str.charAt(i);
            if(!map.containsKey(ch)) map.put(ch,new ArrayList<>());
            map.get(ch).add(i);
       }
       System.out.print(map);
   }
    public static void main(String args[])
    {
        //demo();
        //frequencyMap("aaahhysr");
        getIndex("aaagrsse");
    }

}