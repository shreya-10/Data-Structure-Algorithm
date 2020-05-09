class Solution {
///

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st=new Stack<>();
        
        for(int i=0;i<asteroids.length;i++)
        {
            if(st.size()==0)
            {
                st.push(asteroids[i]);
                continue;
            }
            while(st.size()!=0 && st.peek()>0 && asteroids[i]<0)
            {
                if(-asteroids[i]>st.peek())
                st.pop();
             }
            
                 if(st.size()!=0&&Math.abs(st.peek())==Math.abs(asteroids[i]))
               {
                   st.pop();
                    
               }
            
              st.push(asteroids[i]);
        }
        int[] arr=new int[st.size()];
        int i=arr.length-1;
        while(i>=0)
        {
            arr[i]= st.pop();
            i--;
        }
        return arr;
    }
}