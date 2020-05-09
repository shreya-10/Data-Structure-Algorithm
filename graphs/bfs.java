
import java.util.*;
public static class BFSpair
{
    int vtx=0;
    int wsf=0;
    String psf="";
    BFSpair(int vtx,int wsf,String psf)
    {
        this.vtx=vtx;
        this.wsf=wsf;
        this.psf=psf;

    }

    BFSpair()
    {

    }
}

public static void shortestPath(int src,int dest)
{
    LinkedList<BFSpair> que=new LinkedList<>();
    BFSpair root=new BFSpair(src,0,src+"");
    que.addLast(root);

    while(!que.size())
    {
        BFSpair rpair=que.removeFirst();

        //cycle
        if(vis[])
    }
}