
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
public class binaryTree{
    public static void main(String args[])
    {
     int arr[]={10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
     Node idx=new Node(0,null,null);
    Node root=construct(arr,idx);
     display(root);
    // System.out.println(size(root));
    //  System.out.println(height(root));
    // preorder(root);
    // System.out.println();
    //  postorder(root);
    //  System.out.println();
    //   Inorder(root);
    // //15 oct======================================================================
    // System.out.println(find(root,120));
    //   System.out.println(min(root));
    //    System.out.println(max(root));
    //     ArrayList<Node> path = new ArrayList<>();
    //  rootToNode(root,50,path);
    //     //  Collection.reverse(ans);
    //     for(Node node:path)
    //     System.out.print(node.data+"  ");


    
    //     leafNode(root);
    //16 oct=======================================================================================
    // levelOrder(root);

    // System.out.println();
    levelOrderpattern_02(root);

    //29 oct========================================================================================
//Node ans=commonNode(root,60,80);
    //

  ///   System.out.println(ans.data);

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

    public static int size(Node node)
    {
        if(node==null) return 0;
        return size(node.left)+size(node.right)+1;
    }
     public static int height(Node node)
    {
        if(node==null) return 0;
        return Math.max(height(node.left),height(node.right))+1;
    }

public static void preorder(Node node)
{   if(node==null)
        return;
    System.out.print(node.data+"  ");
    preorder(node.left);
    preorder(node.right);
}
public static void postorder(Node node)
{   if(node==null)
        return;
   
    postorder(node.left);
    postorder(node.right);
     System.out.print(node.data+"  ");
}
public static void Inorder(Node node)
{   if(node==null)
        return;
   
    Inorder(node.left);
     System.out.print(node.data+"  ");
    Inorder(node.right);
}
public static boolean find(Node node,int data)
{ 
    if(node==null)
        return false;
    if(node.data==data)
    {
        return true;
    }
    return find(node.left,data) || find(node.right,data);
    
   
}

public static int max(Node node)
{ if(node==null)
        return  Integer.MIN_VALUE;;

   int m1 = max(node.left);
   int m2=max(node.right);
   int myans=Math.max(m1,m2);
 return Math.max(myans,node.data);

}
public static int min(Node node)
{
if(node==null)
        return  Integer.MAX_VALUE;

   int m1 = min(node.left);
   int m2=min(node.right);
   int myans=Math.min(m1,m2);
 return Math.min(myans,node.data);
}
//shortest path from rootToNode=======================================================================
 public  static ArrayList<Node> rootToNode_02(Node node,int data)
{if(node==null)
return null;
if(node.data==data)
{
    ArrayList<Node> base=new ArrayList<>();
    base.add(node);
    return base;
}
    ArrayList<Node> leftans=rootToNode_02(node.left,data);
    if(leftans!=null)
    {
        leftans.add(node);
        return leftans;
    }

    ArrayList<Node> rightans=rootToNode_02(node.right,data);
    if(rightans!=null) 
    {
        rightans.add(node);
        return rightans;
    }
    return null;
     }
public  static boolean rootToNode(Node node,int data,ArrayList<Node> path)
{
    if(node==null)
    return false;

    if(node.data==data)
    {path.add(node);
    return true;
    }
boolean lr=rootToNode(node.left,data,path);
if(lr==true)
{
    path.add(node);
    return true;
}

boolean rr=rootToNode(node.right,data,path);
if(rr==true)
{
    path.add(node);
    return true;
}
return false;
}

public static void  leafNode(Node node)
{
    if(node==null)
    return;
    if(node.left==null && node.right==null)
    System.out.print(node.data+" ");
    leafNode(node.left);
    leafNode(node.right);
}
//16oct===============================================================================
public static void levelOrder(Node root)
{
    LinkedList<Node> que =new LinkedList<>();
    que.addLast(root);
    while(!que.isEmpty())
    {
        Node n=que.removeFirst();
        System.out.print(n.data+" ");
        if(n.left!=null)
        {
            que.addLast(n.left);
        }
        if(n.right!=null)
        {
            que.addLast(n.right);
        }

    }
}

public static void levelOrderpattern_01(Node root)
{
  LinkedList<Node> que= new LinkedList<>();
  que.addLast(root);

  while(!que.isEmpty())
  {
      int size= que.size();
      while(size-- >0)
      {
          Node proc=que.removeFirst();
           System.out.print(proc.data+" ");
        if(proc.left!=null)
        {
            que.addLast(proc.left);
        }
        if(proc.right!=null)
        {
            que.addLast(proc.right);
        }
      }
      System.out.println();
  }
  }

  //method 2 

  public static void levelOrderpattern_02(Node root)
  {
      LinkedList<Node> que1 = new LinkedList<>();
      LinkedList<Node> que2= new LinkedList<>();
       que1.addLast(root);
    while(!que1.isEmpty())
    {
        Node n=que1.removeFirst();
        System.out.print(n.data+" ");
        if(n.left!=null)
        {
            que2.addLast(n.left);
        }
        if(n.right!=null)
        {
            que2.addLast(n.right);
        }
        if(que1.size()==0)
       {
        System.out.println();
        LinkedList<Node> temp= new LinkedList<>();
        temp=que1;
        que1=que2;
        que2=temp;
    }


    }
    
  }
///LCA===================================================================================

  public static Node commonNode(Node root,int data1,int data2)
  {   ArrayList<Node> one=rootToNode_02(root,data1);
      ArrayList<Node> two=rootToNode_02(root,data2);
      int c;
      Node ans=null;
      if(one==null|| two==null)
      return null;

       for(int i=one.size()-1;i>=0;i--)
       {
       for(int j=two.size()-1;j>=0;j--)
       { 
           if(one.get(i).data==two.get(j).data)
           {
           ans=one.get(i);
           }
           else
           break;
              
       }
       }
      return ans;
  }

//  static Node LCA=null;
// public static boolean commonNode_02(Node node, int data1,int data2)
// {  
//     if(node==null)
//     {
//         return false;
//     }
 
//     boolean selfdone=node.data==data1||node.data==data2;
//     boolean left=commonNode_02(node.left,data1,data2);0
//     boolean right=commonNode_02(node.right,data1,data2);
//     if((left&&right)|| (left && selfdone)|| (right&& selfdone))
//     LCA=node;
//     return left || right|| selfdone;

// } 

}

