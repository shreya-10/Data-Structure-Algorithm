import java.util.*;
class heapCreation
{
   public static class heap
    {
    ArrayList<Integer> arr;
    boolean isMax=false;
    heap()
    {
        arr=new ArrayList<>();
    }
    heap(boolean isMax)
    {
          arr=new ArrayList<>();
        this.isMax=isMax;

    }
    heap(int ar[],boolean isMax)
    {
        this.isMax=isMax;
        arr=new ArrayList<>();
        for(int ele:ar)//O(n)
        {
            this.arr.add(ele);
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
            downHeapify(i);
        }
    }

    public  void swap(int i,int j)
    {
        int val1=arr.get(i);
        int val2=arr.get(j);

        arr.set(i,val2);
        arr.set(j,val1);
    }
    
    public  void downHeapify(int idx)
    {   
        int maxi=idx;
        int lci=2*idx+1;
        int rci=2*idx+2;

        if(lci<arr.size() &&  CompareTo(lci,maxi)>0)
        {
            maxi=lci;
        }
         if(rci<arr.size() &&  CompareTo(rci,maxi)>0)
        {
            maxi=rci;
        }
        if(maxi!=idx)
        {   swap(maxi,idx);
            downHeapify(maxi);
        }
    }

    public   void upHeapify(int cidx)
    {
        int pidx=(cidx-1)/2;

        if(pidx>=0 && CompareTo(cidx,pidx)>0)
        {
            swap(cidx,pidx);
            upHeapify(pidx);
        }
    }

    public  void push(int data)
    {
        arr.add(arr.size()-1,data);
        
        upHeapify(arr.size()-1);
    }
    public  int top()
    {
        return arr.get(0);
    }

    public  int pop()
    {
        swap(0, arr.size() - 1);

            int rele = arr.get(arr.size() - 1);
            arr.remove(arr.size() - 1);
            downHeapify(0);
            return rele;


    }
public  void update(int idx,int data)
{
    arr.set(idx,data);
    upHeapify(idx);
    downHeapify(idx);
}
public   int CompareTo(int child,int par)
{
    if(isMax)
    {
        return arr.get(child)-arr.get(par);
    }
    else
    return arr.get(par)-arr.get(child);
}
public  int size()
{
    return arr.size();
}
}


public static void main(String args[])
{
    int heaparr[]={-1,10,13,2,9,4,-2,5,12,14,11};
    heap  pq=new heap(heaparr,false);
    while(pq.size()!=0)
    {
        System.out.println(pq.pop()+" ");
    }
    
}


}