public class bst{


public static void main(String args[])
{


}

public static class pair{
    int max;
    int min=INTEGER_MAXVALUE;
     bool isBST=true;
    
     int countBST=0;
}
public static pair BST(Node node)
{
if(left.isBST && right.isBST && left.max<=node.data && right.min>=node.data)
{
    
}
}
}



public static boolean isBST(Node  curr)
{

    if(curr==null)
    return true;
    
    
    
        boolean left=isBST(curr.left);
    if(!left)
    return false;

    if(prev<curr.data)
    prev=curr.data;

    else
    return false;

    boolean right=isBST(curr.right);
        if(!right)
        return false;
return  true;
}

public static int diameter_01(Node node)
{
    if(node==null)
    return 0;

    int lh=height(node.left);  //previously made fn
    int rh=height(node.right);

    //every node is visited one and their respective heights are calculated.

    int ld= diameter_01(node.left);
    int rd=diameter_01(node.right);

    //every node is visited twice after the above calls hence it is in O(n^2) complexity

    return Math.max(Math.max(ld,rd),lh+rh+1);

}



public static class diaPair
{
    int height=0;
    int dia=0;

}

public static diaPair diameter_02(Node node)
{
    if(node==null)
    return new diaPair();

    diaPair left=diameter_02(node.left);
    diaPair right=diameter_02(node.right);

    diaPair mypair= new diaPair();
    mypair.height=Math.max(left.height,right.height);
    mypair.dia=Math.max(Math.max(left.dia,right.dia),left.height+right.height+1);
    return mypair;
}

public static void deleteLeaf_01(Node node,int leaf)
{
    if(node ==null)
    return;
    if(node.left!=0 && node.left.data==leaf)
    node.left=null;

    if(node.right!=0 && node.right==leaf)
    node.right=null;
}
public static Node deleteLeaf_02(Node node,int leaf)
{
    if(node==null)
    return null;
    if(node.leaf==null && node.right==null && node.data=leaf )  return null;
    node.left=deleteLeaf_02(node.left,leaf);
    node.right=deleteLeaf_02(node.right,leaf);
    return node;
}


public static void addLeaf_01(Node node,int par,int leaf,boolean isLeft)
{
    if(node==null)
    return null;
    if(node.data==par)
    {
        if(isLeft)
        node.left=new Node(leaf);
        else 
        node.right=new Node(leaf);
    }
    node.left=addLeaf_01(node.left,par,leaf,isLeft);
    node.right=addLeaf_01(node.right,par,leaf,isLeft);
    
}
//binary tree delete any node.
public static  void delete(Node node,int data)
{
if(node==null)
return null;
if(node.data==data)
{
    if(node.left==null&& node.right ==null)
    return null;
    else if(node.left==null)
    return node.right;
    else   //(node.right==null)
    return node.left;


}
node.left=delete(node.left,data);
node.right=delete(node.right,data);
return node;
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

//addition and deletion in BST
void addNode_01(Node node,Node par,int data,bool isLeft)
{   if(node==null)
{
    Node child=new Node(data);
    if(isLeft)
    par.left=child;
    else
    par.right=child;
    return;
}
    if(node.data==data)  //this condition is hit only in case of adding duplicate node.
                          //it doesnt add duplicate node but increases the frequency.
    {
      node.freq++;      
      return;
    }
    else if(data<node.data)
    addNode_01(node.left,node,data,true);
    else //(data>node.data)
    addNode_01(node.right,node,data,false);
}
}

Node addNode_02(Node node,int data)
{
    if(node==null)
    return new Node(data);

    if(data<node.data)
     node.left=addNode_02(node.left,data);
     else
     node.right=addNode_02(node.right,data);
     return node;

}
Node deleteNode_01(Node node,int data)
{ if(node==null)
  return;
     if(node.data==data)
    {
     if(node.left==null && node.right==null)  //leaf node
     return null;

     else if(node.left==null)   //single child
     return node.right;
     else if(node.right==null)  //single child
     return node.left;
    else                         //two childst
    {                             //left child ka rightmost element which is max in left tree
        int max=maximum(node.left);   //previously written maximum fn gives max node of left tree 
        node.data=max;
        node.left=deleteNode_01(node.left,max);
              
    }



}
    if(data<node.data)
    node.left=deleteNode_01(node.left,data);
    else
    node.right=deleteNode_01(node.right,data);
}
