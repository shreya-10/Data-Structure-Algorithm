#include<iostream>
#include<vector>

using namespace std;

vector<int> mapping(26);
 string str1="send";
string str2="more";
string str3="money";
int unused=0;

int stringtoNumber(string str)
{
    int num=0;
    for(int i=0;i<str.length();i++)
    {
    int idx=str[i]-'a';
    int val=mapping[idx];
    num=num*10+val;
    }
    return num;
}

int cryptorecursive(string str,int idx)
{
    if(str.length()==idx)
    {
        int a=stringtoNumber(str1);
        int b=stringtoNumber(str2);
        int c=stringtoNumber(str3);
        if(a+b==c)
        {
            return 1;
        }
        return 0;
    }
    int count=0;

    for(int num=0;num<=9;num++)
    {
        int mask=(1<<num);
        if((unused & mask)==0)
        {   unused^=mask;
            mapping[str[idx]-'a']=num;
            count+=cryptorecursive(str,idx+1);
            unused^=mask;
            mapping[str[idx]-'a']=0;
            
            
        }

    }
    return count;
}

void uniqueChar(string str)
{
    int unique=0;
    for(int i=0;i<str.length();i++)
    {
        int idx=str[i]-'a';
        int mask=(1<<idx); 
        unique|=mask;     //set the bit
    }
    str="";
    for(int i=0;i<26;i++)
    {
        int mask=(1<<i);
        if((mask & unique)!=0)
        str+=(char)(i+'a');
    }
    cout<<str;
    cout<<cryptorecursive(str,0);
}
 
int main(int ard,char** arg)
{
   
     string str=str1+str2+str3;
     uniqueChar(str);

}