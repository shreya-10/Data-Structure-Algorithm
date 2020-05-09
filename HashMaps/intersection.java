import java.util.*;
 class intersection {
    // public int[] intersectionArray(int[] nums1, int[] nums2) {
    //     HashMap<Integer,Integer> map= new HashMap<>();
    //     int[] arr=new int[nums2.length];
    //     for(int i=0;i<nums1.length;i++)
    //     {
    //         if(!map.containsKey(nums1[i]))
    //         maps.put(nums1[i],i);
    //     }
    //     int k=0;
    //     for(int a:map.keySet())
    //     {
    //             for(int i=0;i<nums2.length;i++)
    //             {      
    //                 if(nums2[i]==a)
    //                 {
    //                 arr[k]=nums2[i];
    //                 k++;
    //                 break;
    //                 }
    //             } 
        
    //     }

    //     int[] ans=new int[k];
    //     for(int i=0;i<k;i++)
    //     {
    //         ans[k]=arr[k];    
    //     }
    //     return ans;
        
    // }
    public static int[] intersection(int nums1[], int nums2[])
    {
        int arr[]=new int[nums2.length];
        int k=0;
        HashMap<Integer,Boolean> map= new HashMap<>();
        for(int el:nums1)
        {
            map.put(el,true);
            
        }
            for(int el:nums2)
        {
            if(map.containsKey(el))
            {
                arr[k]=el;
                k++;
                map.remove(el);
            }


         }

         int ans[]=new int[k];
          for(int i=0;i<k;i++)
        {
            ans[i]=arr[i];    
        }
        return ans;
    }

public static void  intersection_02(int nums1[], int nums2[])
{
    HashMap<Integer,Integer> map= new HashMap<>();
    for(int el:nums1)
    {
        map.put(el,map.getOrDefault(el,0)+1);

    }
    for(int el:nums2)
    {
        if(map.containsKey(el))
        {
            System.out.print(el+" ");
            if(map.get(el)==1)map.remove(el);
            else map.put(el,map.get(el)-1);

        }
    }


}
    public static void main(String args[])
    {
        int num1[]={1,1,1,2,2,3,5};
        int num2[]={1,1,2,2,3};
       int ans[]= intersection(num1,num2);
        for(int el:ans)
    {
        System.out.print(el+" ");
    }
       // intersection_02(num1,num2);
       
    }
}