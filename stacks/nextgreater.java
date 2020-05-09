import java.util.*;
public class nextgreater
{
    public static void NGEright(int arr[])
    {
        Stack<Integer> st=new Stack<>();
        
       
        for(int i=0;i<arr.length;i++)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
                continue;  
            }
            while(st.size()!=0 && arr[i]>st.peek())
            {
               
                System.out.println(st.peek()+"->" +arr[i]);
                 st.pop();

            
            }
            st.push(arr[i]);  
        }

        while(st.size()!=0)
        {
            System.out.println(st.peek()+"->" +-1);
            st.pop();

        }

    } 


    public static void NGEleft(int arr[])
    {
        Stack<Integer> st=new Stack<>();
        
       
        for(int i=arr.length-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
                continue;  
            }
            while(st.size()!=0 && arr[i]>st.peek())
            {
               
                System.out.println(st.peek()+"->" +arr[i]);
                 st.pop();

            
            }
            st.push(arr[i]);  
        }

        while(st.size()!=0)
        {
            System.out.println(st.peek()+"->" +-1);
            st.pop();

        }

    } 


    public static void NSEright(int arr[])
    {
        Stack<Integer> st=new Stack<>();
        
       
        for(int i=0;i<arr.length;i++)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
                continue;  
            }
            while(st.size()!=0 && arr[i]<st.peek())
            {
               
                System.out.println(st.peek()+"->" +arr[i]);
                 st.pop();

            
            }
            st.push(arr[i]);  
        }

        while(st.size()!=0)
        {
            System.out.println(st.peek()+"->" +-1);
            st.pop();

        }

    } 


    public static void NSEleft(int[] arr)
    {
        Stack<Integer>  st=new Stack<>();

        for(int i=arr.length-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
                continue;
            }
            while(st.size()!=0 && arr[i]<st.peek())
            {
                System.out.println(st.peek()+"->" +arr[i]);
                 st.pop();
            }

            st.push(arr[i]);
        }
      while(st.size()!=0)
        {
            System.out.println(st.peek()+"->" +-1);
            st.pop();

        }

     }
    public static void main(String args[])
    {
        int arr[]={9,1,7,3,11,25,20,15,10};
        NGEleft(arr);
        //NGEright(arr);
        //NSEleft(arr);
        //NSEright(arr);
    }
}
