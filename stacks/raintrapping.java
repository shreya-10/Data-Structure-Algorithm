class Solution {
    public int trap(int[] height) {
        int leftmax[]=new int[height.length];
        int rightmax[]=new int[height.length];
        int sum=0;
        if(height.length!=0)
        {
        leftmax[0]=height[0];
      rightmax[leftmax.length-1]=height[leftmax.length-1];
        for(int i=1,j=height.length-2;i<leftmax.length   && j>=0;i++,j--)
        {
            leftmax[i]=Math.max(height[i],leftmax[i-1]);
            rightmax[j]=Math.max(height[j],rightmax[j+1]);
        }
        int arr[]=new int[height.length];
        
          for(int i=0;i<leftmax.length;i++)
          {
              arr[i]=Math.min(leftmax[i],rightmax[i])-height[i];
              sum+=arr[i];
          }
        }
        return sum;
    }
}class Solution {
    public int trap(int[] height) {
        int leftmax[]=new int[height.length];
        int rightmax[]=new int[height.length];
        int sum=0;
        if(height.length!=0)
        {
        leftmax[0]=height[0];
      rightmax[leftmax.length-1]=height[leftmax.length-1];
        for(int i=1,j=height.length-2;i<leftmax.length   && j>=0;i++,j--)
        {
            leftmax[i]=Math.max(height[i],leftmax[i-1]);
            rightmax[j]=Math.max(height[j],rightmax[j+1]);
        }
        int arr[]=new int[height.length];
        
          for(int i=0;i<leftmax.length;i++)
          {
              arr[i]=Math.min(leftmax[i],rightmax[i])-height[i];
              sum+=arr[i];
          }
        }
        return sum;
    }
}