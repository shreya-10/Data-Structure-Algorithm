
    public class queue
    {   int que[];
        int head=0;
        int tail=-1;
        int size=0;
    
    queue()
    {
        this.que=new int[10];
    }
    queue(int size)
    {
        this.que=new int[size];

    }
    public  int size()
    {
        return this.size;
    }
    public boolean isEmpty()
    {
        return this.size==0;
    }

    public void display()
    {
        for(int i=0;i<this.size;i++)
        {
            int val=que[(this.head+i)%que.length];
            System.out.print(val+"  ");
        }
    System.out.println();
    }
    public void push(int data)
    {
        if(this.size==que.length)
        {
            System.out.println("overflow!!");
            return;
        }
        this.tail=(this.tail+1)%que.length;
        que[tail]=data;
        size++;
    }
    public int pop()
    {
        if(this.size==0)
        {
            System.out.println("underflow!!");
            return -1;
        }

        int rv=que[head];
        que[head]=0;
        head=(head+1)%que.length;
        size--;
        return rv;
    }

    public int front()
    {
        if(this.size==0)
        {
            System.out.println("underflow!!");
            return -1;
        }


        return que[head];

    }
}
