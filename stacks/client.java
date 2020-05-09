public class client
{
    public static void solveStack()
    {
        stack st= new stack(5);
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        st.display();
        //st.push(60);
    }

    public static void solveQueue()
    {
        // queue que= new queue(4);
        // que.push(10);
        // que.push(20);
        // que.push(30);
        // que.push(40);
        // que.display();
        // que.pop();
        // que.pop();
        // que.push(50);
        // que.push(60);
        // que.push(70);
        // que.display();
        // System.out.println(que.front());

       dynamicQueue dq=new dynamicQueue();
        dq.push(10);
        dq.push(20);
        dq.push(30);
        dq.push(40);
        dq.pop();
        dq.push(50);
        dq.push(70);
        dq.display();
    }
    public static void main(String args[])
    {
       solveQueue();
    }
}