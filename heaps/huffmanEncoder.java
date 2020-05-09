import java.util.HashMap;
import java.util.PriorityQueue;
public class  huffmanEncoder
{

    huffmanEncoder(String str)
    {
        HuffmanTree(str);
    }

    HashMap<String,String> encode=new HashMap<>();
    HashMap<String,String> decode=new HashMap<>();
    class Node implements Comparable<Node>
    {
        String data="";
        int freq;
        Node left;
        Node right;

    public Node(String data,int freq,Node left,Node right)
    {
        this.data=data;
        this.freq=freq;
        this.left=left;
        this.right=right;
    }

    @Override
    public int compareTo(Node o)
    {
        return this.freq=o.freq; //min heap
    }

    }

    private  void HuffmanTree(String str)
    {
     
        char freq[]=new char[26];
        for(int i=0;i<str.length();i++)
        {
            char c=str.charAt(i);
            freq[c-'a']++;
        }
        PriorityQueue<Node> pq=new PriorityQueue<>();
       for(int i=0;i<freq.length;i++)
        {
            if(freq[i]>0)
            pq.add(new Node((char)(i+'a')+"",freq[i],null,null));
        }


        while(pq.size()!=1)
        {
            Node a=pq.poll();
            Node b=pq.poll();

            Node c=new Node("",a.freq+b.freq,a,b);
            pq.add(c);
        }
         Huffmantraversal(pq.peek(),"");

    }

    private  void Huffmantraversal(Node node,String Binarycode)
    {
        if(node.left==null && node.right==null)
        {
            encode.put(node.data,Binarycode);
            decode.put(Binarycode,node.data);
            return;
        }
        Huffmantraversal(node.left,Binarycode+"0");
        Huffmantraversal(node.right,Binarycode+"1");

    }


    public  String encodeString(String input)
    {
            StringBuilder ans=new StringBuilder();

        for(int i=0;i<input.length();i++)
        {
            String s=input.charAt(i)+"";
          ans.append(encode.get(s));
           
        }
        return ans.toString();
    }

    public  String decodeString(String input)
    { StringBuilder ans=new StringBuilder();
        int j=0;
        for(int i=1;i<=input.length();i++)
        {
            String pos=input.substring(j,i);
            if(decode.containsKey(pos)==true)
            {
                j=i;
                ans.append(decode.get(pos));
            }
        }
        return ans.toString();
    }
  
}