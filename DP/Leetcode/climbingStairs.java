class climbingStairs {
    //memoization
    public static int climbStairs(int n,int arr[]) {
        
        if(n==0)
            return 1;
        int count=0;
        if(arr[n]!=0) return arr[n];
        if(n-1>=0)
        count+=climbStairs(n-1,arr);
        if(n-2>=0)
        count+=climbStairs(n-2,arr);
        arr[n]=count;
        return count;
        
    }
    //tabulation
     public static int climbStairs_02(int n,int arr[]) {
        for(int i=0;i<=n;i++)
        {
        if(i==0)
        {
            arr[i]=1;
            continue;
        }
        int count=0;
        if(i-1>=0)
        count+=arr[i-1];
        if(i-2>=0)
        count+=arr[i-2];
        arr[i]=count;
        }
        return arr[n];
        
    }
    //optimization
    public static int climbStairs_03(int n) {
        if(n<=1)
        return 1;
        int a=1,b=1,ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=a+b;
            a=b;
            b=ans;
            
        }
        return ans;
        
    }
    public static void display(int arr[])
    {
        for(int el:arr)
        {
         System.out.print(el+" ");


        }
    }
      public static void main(String args[])
    {
        int n=10;
        int arr[]=new int[n+1];
        // System.out.print(climbStairs(n,arr)+"\n");
        System.out.print(climbStairs_02(n,arr)+"\n");
        display(arr);
    }
}