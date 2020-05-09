import java.util.*;

public class intro{
    public static class edge
    {
        int v=0;
        int  w=0;
        edge(int v,int w)
        {
            this.v=v;
            this.w=w;
        }
    }
    public static ArrayList<ArrayList<edge>> graphs=new ArrayList<>();



public static void removevtx(int u)
{
    ArrayList<edge> vtxEdges=graphs.get(u);
    while(vtxEdges.size()!=0)
    {
        int lidx=vtxEdges.size()-1;
        edge e=vtxEdges.get(lidx);
        removeEdge(u,e.v);
    }

}

public static void removeEdge(int u,int v)
{
    int i=0,j=0;
    while(i<graphs.get(u).size())
    {
        edge e=graphs.get(u).get(i);
        if(e.v==v)
        break;


        i++;
    }

     while(j<graphs.get(v).size())
    {
        edge e=graphs.get(v).get(j);
        if(e.v==u)
        break;

        
        j++;
    }
    graphs.get(u).remove(i);
    graphs.get(v).remove(j);
}
 public static void display()
    {
        for(int i=0;i<graphs.size();i++)
        {
            System.out.print(i+"->");
            for(edge  e:graphs.get(i))
            {
                System.out.print("("+e.v+","+e.w+")");
            }
             System.out.println();
        }

    }



    public static void addEdge(int u,int v,int w)
    {
        if(u<0 || v<0 || u>=graphs.size() || v>=graphs.size())
        return;

        graphs.get(u).add(new edge(v,w));
        graphs.get(v).add(new edge(u,w));
    }

    
    public static void construction()
    {
        int n=7;//no of vertices
        for(int i=0;i<n;i++)
        graphs.add(new ArrayList<>());
         
        addEdge(0,3,40);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,10);
        addEdge(3,4,2);
        addEdge(4,5,3);
        addEdge(5,6,3);
        addEdge(4,6,8);

        display();
        

    }


    public static void main(String args[])
    {
        construction();
       // removeEdge(3,4);

       removevtx(3);
        display();
    }
   
    

}