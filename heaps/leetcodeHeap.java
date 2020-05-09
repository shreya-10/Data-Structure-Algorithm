
class Solution {
    //Leetcode 215 
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<k;i++)
        pq.add(nums[i]);//taking O(k) space
        
        for(int i=k;i<nums.length;i++)
        {
            if(nums[i]>pq.peek())
            {
                pq.remove();
                pq.add(nums[i]);
                
            }
        }
        return pq.peek();
    }
}

//second method  //preferrrable O(1) space


class Solution {
    public  void swap(int i,int j,int[] nums)
    {
        int val1=nums[i];
        nums[i]=nums[j];
        nums[j]=val1;

    }
    public  void downHeapify(int[] nums,int idx,int lidx)
    {   
        int maxi=idx;
        int lci=2*idx+1;
        int rci=2*idx+2;

        if(lci<=lidx && nums[lci]>nums[maxi])
        {
            maxi=lci;
        }
         if(rci<=lidx&&  nums[rci]>nums[maxi])
        {
            maxi=rci;
        }
        if(maxi!=idx)
        {   swap(maxi,idx,nums);
            downHeapify(nums,maxi,lidx);
        }
    }
     public int findKthLargest(int[] nums, int k) {
         int n=nums.length-1;
         for(int i=n;i>=0;i--)
         downHeapify(nums,i,n);
         
         for(int i=0;i<k;i++)
         {
             swap(0,n-i,nums);
             downHeapify(nums,0,n-i-1);
         }
         return nums[n-k+1];
    }
}