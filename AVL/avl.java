public class avl
{
    public static class Node
    {
        int data=0;
        Node left=null;
        Node right=null;
        int height=-1;
        int balance=0;
    
    Node(int data)
    {
        this.data=data;
        this.height=0;

        
    }
    }

    public static Node  create(int[] arr,int si,int ei)
  {
    if(si>ei)
    return null;
    int mid=(si+ei)/2;
    Node node =new Node(arr[mid]);
   
    node.left=create(arr,si,mid-1);
    node.right=create(arr,mid+1,ei);
    getfactor(node);


    return node;

    }
//display
   public static void display(Node node)
    {
        if(node==null)
        return;

        StringBuilder sb=new StringBuilder();
        sb.append(node.left!=null?node.left.data:".");
        sb.append("->"+node.data+"<-");
        sb.append(node.right!=null?node.right.data:".");
        sb.append(" node balance is  "+node.balance);
        System.out.println(sb.toString());

        display(node.left);
        display(node.right);


    }
public static int getHeight(Node node)
{  if(node==null)
    return -1; //in terms of edges  
    int lh=-1;
    int rh=-1;
    if(node.left!=null)  lh=node.left.height;
    if(node.right!=null) rh=node.right.height;
    return Math.max(lh,rh)+1;
}
public static int getBalance(Node node)
{if(node==null)
    return 0;
    int lh=-1;
    int rh=-1;
    if(node.left!=null)  lh=node.left.height;
    if(node.right!=null) rh=node.right.height;
    return lh-rh;
}


public static void getfactor(Node node)
{node.height=getHeight(node);
node.balance=getBalance(node);

}

public static Node RR(Node node)
{
    Node n=node.left;
    Node temp=n.right;
    n.right=node;
    node.left=temp;
    getfactor(node);
    getfactor(n);
    return n;
}

public static Node LL(Node node)
{
    Node n=node.right;
    Node temp=n.left;
    n.left=node;
    node.right=temp;;
    getfactor(node);
    getfactor(n);
    return n;
}
public static Node updatefactors(Node node)
{ 
    if(node.balance>1)//ll lr
    {
        if(node.left.balance>0)
        node=RR(node);
        else{
        node.left=LL(node.left);
        node=RR(node);
        }
    }   
    else if(node.balance<-1) //rr rl
    {
        if(node.right.balance<0)
        node=LL(node);
        else{
        node.right=RR(node.right);
        node=LL(node);
        }
    }
    return node;
}

public static Node addData(Node node,int data)
{
    if(node==null)
    {
    return new Node(data);
    }

    if(data<node.data)
     node.left=addData(node.left,data);
     else
     node.right=addData(node.right,data);

    getfactor(node);
    node=updatefactors(node);
    return node;
}
public static void main(String args[])
{
int arr[]={20,30,40,50,60};
     
    Node root=create(arr,0,4);
    display(root);
    System.out.println();
    Node newroot=addData(root,70);
      display(newroot);
}    
}
