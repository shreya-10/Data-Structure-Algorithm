class arr
{

    public static void swap(int arr[],int i,int j)
    {   int temp =arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public static void main(String args[])
    {
        int arr[]={0,1,2,3};
        swap(arr,0,2);

        System.out.println(arr[0] + "  "+ arr[2]);
    }
}