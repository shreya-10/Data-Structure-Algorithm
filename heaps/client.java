class client
{
    public static void main(String args[])
    {
        huffmanEncoder hed=new huffmanEncoder("snshshjhuaaaajiusiajsksndjenwewoeoqnndepaejwjsnjdbjasfhajss");
        String str="asshu";
        String encode=hed.encodeString(str);
        String decode=hed.decodeString(encode);

        System.out.println(encode);
        System.out.println(decode);
    } 


   
}