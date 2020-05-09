#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
 unordered_set<string> map;
int wordbreak(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=1;i<=str.length();i++)
    {
        string smallstr=str.substr(0,i);
        if(map.find(smallstr)!=map.end())
        {
             count +=wordbreak(str.substr(i),ans+smallstr+" ");
        }
    }
    return count;
}

int main(int ard,char** arg)
{
    vector<string> dict={"i","like","sam","sung","samsung","ilike"};
    string str="ilikesamsung";
   
    for(string word:dict)
    map.insert(word);
    wordbreak(str,"");

}