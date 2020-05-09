#include<iostream>
#include<vector>
using namespace std;

string words[]={"yz",":;","abc","def","ghi","jkl","mno","pqrs","uv","wx","*#@","+-"};

vector<string> nokia_keypad(string str)
{
    if(str.length()==0)
    {
      vector<string>  base;
      base.push_back("");
      return base;
    }

    char ch=str[0];
    int idx=ch-'0';
    string word=words[idx];
    vector<string> ans=nokia_keypad(str.substr(1));
    vector<string> myans;
    for(string s:ans)
    {
        for(char letter:word)
        {
            myans.push_back(letter+s);
        }
    }
    if(str.length()>1)
    {
        char ch=str[1];
        int idx1=ch-'0';
        int num=idx*10+idx1;
        if(num>=10 && num<=11)
        {
        string word=words[num];
    ans=nokia_keypad(str.substr(2));
    
    for(string s:ans)
    {
        for(char letter:word)
        {
            myans.push_back(letter+s);
        }
    }
    }
    

}
return myans;
}
int nokia_keypad_02(string ques,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    char ch=ques[0];
    int idx=ch-'0';
     string word=words[idx-1];
     for (int i=0;i<word.length();i++)
     {
        count+= nokia_keypad_02(ques.substr(1),ans+word[i]);
     }
     return count;
}

int encoding(string ques,string ans)
{
     if(ques.length()==0)
    {
        cout<<ans<<" ";
        return 1;
    }
    
    int count=0;
    char ch=ques[0];
    int idx=ch-'0';
    if(idx==0) return 0;
     char word='a'+idx-1;
      
        count+= encoding(ques.substr(1),ans+word);
     

     if(ques.size()>1)
     {
         int idx1=ques[1]-'0';
         int num=idx*10+idx1;
        char nword=num+'a'-1;
        if(num>=10 && num<=26)
        {
            count+=encoding(ques.substr(2),ans+nword);
        }

     }
     return count;
}
  int main(int arg,char** b)  
{
      vector<string> ans=nokia_keypad("108");
     for(string str:ans)
     cout<< str<<" ";
    //  cout<<nokia_keypad_02("589","");
    // cout<<encoding("1123","");
    // cout<<encoding("1321","");
  // cout<<encoding("1023","");
//     cout<<encoding("1203","");
 }
