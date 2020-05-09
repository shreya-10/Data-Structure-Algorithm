class MinStack {
//O(1) SPACE O(1) TIME
    /** initialize your data structure here. */
    Stack<Long> st;
    long min=Integer.MAX_VALUE;
    public MinStack() {
       st =new Stack<>();
    }
    
    public void push(int x) {
        long val=x;
       if(st.size()==0)
       {
           min=val;
           st.push(val);
           return;
       }
        if(val>=min)
        {
            st.push(val);
        }
        else
        {
            //int y=2*x-min;//encrypted value
             st.push(val-min+val);
            min=x;
        }
    }
    
    public void pop() 
    {
        if(st.peek()>=min)
            st.pop();
        else
        {
             min=min-st.peek()+min;
            st.pop();
          }   
        
    }
    
    public int top() {
        if(st.peek()<=min)
            return (int)min;
        else
        { long t= st.peek();
         return (int)t;
        }
    }
    
    public int getMin() {
        return (int)min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */





//O(1) TIME O(N) SPACE
 class MinStack {
** initialize your data structure here. */
Stack st=new Stack<>();
Stack minst=new Stack<>();
    public MinStack() {
         minst.push(Integer.MAX_VALUE);

    }
    
    public void push(int x) {
        st.push(x);
        minst.push(math.min(x,minst.peek()));

    }
    
    public void pop() {
        st.pop();
        minst.pop();
        
    }
    
    public int top() {
        return st.peek();
            }
    
    public int getMin() {
        return  minst.peek();
        
    }
}