import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
public class prein{
    public static void main(String args[])
    {
     int pre[]={10,20,40,50,60,30,70,90,80};
     int in[]={40,20,60,50,10,70,90,30,80};
     int post[]={40,60,50,20,90,70,80,30,10};
     
  
    Node mytree=PostIn(post,in,0,8,0,8);
    display(mytree);
    }

    public static class Node{
        int data=0;
        Node left=null;
        Node right=null;
        Node(int data,Node left,Node right)
        {
            this.data=data;
            this.left=left;
            this.right=right;
        }
        Node(int data)
        {
            this.data=data;
        }
    }




     public static  Node construct(int[] arr,Node idx)
    { 
        if(idx.data>=arr.length|| arr[idx.data]==-1)
        {
            idx.data++;
            return null;
        }
    Node node =new Node(arr[idx.data],null,null);
    idx.data++;
    node.left=construct(arr,idx);
    node.right=construct(arr,idx);
    return node;

    }
  
    public static void display(Node node)
    {
        if(node==null)
        return;

        StringBuilder sb=new StringBuilder();
        sb.append(node.left!=null?node.left.data:".");
        sb.append("->"+node.data+"<-");
        sb.append(node.right!=null?node.right.data:".");
        System.out.println(sb.toString());

        display(node.left);
        display(node.right);


    
    }
    //construct tree using inorder and preorder
public static Node PreIn(int[] pre, int[] in,int ps,int pe,int is, int ie)
{
    if(ps>pe || is>ie)
    return null;


    Node node= new Node(pre[ps]);
    int idx=is;
    while(idx<=ie)
    {
        if(in[idx]==pre[ps])
        break;
        idx++;
    }
    int tne=idx-is;

    node.left=PreIn(pre,in,ps+1,ps+tne,is,idx-1);
    node.right=PreIn(pre,in,ps+tne+1,pe,idx+1,ie);
    
    return node;
}

public static Node PostIn(int[] post, int[] in,int ps,int pe,int is, int ie)
{
    if(ps>pe || is>ie)
    return null;


    Node node= new Node(post[pe]);
    int idx=is;
    while(idx<=ie)
    {
        if(in[idx]==post[pe])
        break;
        idx++;
    }
    int tne=idx-is;

    node.left=PostIn(post,in,ps,ps+tne-1,is,idx-1);
    node.right=PostIn(post,in,ps+tne,pe-1,idx+1,ie);

    
    
    return node;
}
}