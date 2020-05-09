  class heapsort
  {
  public static void swap(int arr[],int i,int j)
    {   int temp =arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
     public static int CompareTo(int arr[],int child,int par,boolean isMax)
  {
      if(isMax)
      {
          return arr[child]-arr[par];
      }
      else 
      return arr[par]-arr[child];
  }


  public static void downHeapify(int arr[],int idx,int lidx,boolean isMax)
    {   
        int maxi=idx;
        int lci=2*idx+1;
        int rci=2*idx+2;

        if(lci<=lidx &&  CompareTo(arr,lci,maxi,isMax)>0)
        {
            maxi=lci;
        }
         if(rci<=lidx &&  CompareTo(arr,rci,maxi,isMax)>0)
        {
            maxi=rci;
        }
        if(maxi!=idx)
        {   swap(arr,maxi,idx);
            downHeapify(arr,maxi,lidx,isMax);
        }
    }

    public static void main(String args[])
    {
        int arr[]={10,20,30,-2,-3,-3,5,6,7,8,9,22,11,13};
        int n=arr.length-1;
        boolean isMax=false;

        for(int i=n;i>=0;i--)
        downHeapify(arr,i,n,isMax);

        for(int i=0;i<=n;i++)
        {
            
       
            swap(arr,0,n-i);
            downHeapify(arr,0,n-i-1,isMax);
        }
    for(int el:arr)
         {
        System.out.print(el+" ");

        }
    }
  }