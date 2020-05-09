public class dynamicStack extend stack
{
    @Override
    public void push(int data)
    {
        if(this.tos+1==this.st1.length)
        {

            int temp[]=this.st1;
            this.st1=new int[2*temp.length];
            for (int i = 0; i < temp.length; i++) {
                st[i] = temp[i];
        }
        super.push(data);
    }

}       