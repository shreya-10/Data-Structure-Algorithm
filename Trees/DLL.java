public class DLL
{
    static Node prev=null;
    static Node head=null;

    public static void DLL(Node curr)
    {   if(curr==null)
        return;
        
        DLL(curr.left);
        if(head==null)
        {
           

        }
        else
        {
        prev.right=curr;
        curr.left=prev;
        }
        prev=curr;

       }
DLL(node.right);
    }
}