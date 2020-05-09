
public  class stack
{
    int st[];
    int tos=-1;

stack()
{
    this.st=new int[1];
}
stack(int size)
{
    this.st=new int[size];

}
stack (int arr[])
{
    this.st=new int[2*arr.length];
    for(int i=0;i<arr.length;i++)
    this.st[i]=arr[i];

    this.tos=arr.length-1;
}

public int size()
{
    return tos+1;

}
public boolean isEmpty()
{
    return tos==-1;

}
public int top()
{
     if(tos==-1)
    {
      System.out.println("underflow!!");
        return -1;  
    }
    return st[tos];

}
public int pop()
{
    if(tos==-1)
    {
      System.out.println("underflow!!");
        return -1;  
    }
    int rv=st[tos];
    st[tos]=0;
    tos--;
    return rv;

}
public void push(int data)
{
    
    if(tos+1==st.length)
    {
        System.out.println("overflow!!"+(tos+1));
        return;
    }
    st[++tos]=data;


}
public void display()
{
    for(int i=tos;i>=0;i--)
     System.out.print(st[i]+" ");
}

}
// public static void main(String args[])
// {
//     stack st1=new stack();
//     st1.push(30);
//     st1.pop();
//     System.out.println(st1.isEmpty());
//     st1.push(40);
//     System.out.println(st1.size());
//     st1.display();
// }
