import java.util.ArrayList;
class gt
{
    public class Node
    {
        int data=0;
        ArrayList<Node> children=new ArrayList<>();
    
    Node(int data)
    {
    this.data=data;
    }
    }
    public static  Node create(int[] arr)
    { 
    LinkedList<Node> st=new LinkedList<>();
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr[i]!=-1)
        {
            Node node=new Node(arr[i]);
            st.addFirst(node);

        }
        else
        {
            Node rnode=st.removeFirst();
            st.getFirst().children.add(rnode);
        }
        return st.removeFirst();
    }


    }
      public static void display(Node node)
    {
        

        StringBuilder sb=new StringBuilder();
        sb.append(node.data+"->"+"[");
         for(Node child:children)
        sb.append(child.data+","); 


        sb.append("]");   
        System.out.println(sb.toString());
   

        for(Node child:children)
        display(child);
        


    }


      
    public static void main(String args[])
    {
        int arr[]={10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,100,-1,110,-1,-1,120,-1,-1,130,-1,-1};

       Node root= create(arr);
       display(root);
    }
}