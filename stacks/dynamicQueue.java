public class dynamicQueue extends queue
{
     dynamicQueue()
    {
        this.que=new int[1];
    }
    @Override
    public void push(int data)
    {
        if(this.size==que.length)
        {
            int temp[]=this.que;
            this.que=new int[2*temp.length];
              for (int i = 0; i < this.size; i++) {
                que[i] = temp[(this.head + i) % temp.length];
            }

            this.head=0;
            this.tail=temp.length-1;
        }
        super.push(data);
    }
}