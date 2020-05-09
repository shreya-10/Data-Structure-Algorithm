#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
int a[100005],i,m,ans,k,l,j,q,x,n,ma,mi;
char c[100005],s2[100005];
string s,s1;
vector<int> zf (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
int main(int arg,char** argb)
{
    //  char ch='a',newch;
    //  newch=ch+3;
    //  //cout<<newch;
    //  string s="hey";
    //  int i=0;
    //  while(s[i]!='\0')
    //  {  
    //      s[i]='a'+(s[i]-'a'+3)%26;
    //      i++;
    //  }
     //cout<<s;
     string s,s1;
     int n;
          cin>>n;

        while(n--)
        {
            cin>>s;
            cin>>s1;

            vector<int> p1=zf(s1+"$"+s);
            for(int i=0;i<p1.size();i++)
            cout<<p1[i]<<"  ";
            cout<<endl;
            string S=s,S1=s1;
            reverse(S1.begin(),S1.end());
            reverse(S.begin(),S.end());
            vector<int> p2=zf(S1+"$"+S);
            reverse(p2.begin(),p2.end());


            for(int i=s1.size()+1;i<p1.size();i++)p1[i-s1.size()-1]=p1[i];

            k=s1.size();

            for(int i=0;i<s.size()-k+1;i++)
            {
                if(p1[i]+p2[i+k-1]>=k-1)cout<<i<<" ";
            }
                cout<<endl;
        }
l

}