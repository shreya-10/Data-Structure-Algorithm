#include<iostream>
#include<vector>
#include<list>
using namespace std;
int fibonacci(int n)
{
    if(n<=1)
    return n;
int ans=fibonacci(n-1)+fibonacci(n-2);
return ans;

}


int fibonacci_02(int n,vector<int>& mem) //fibonacci
{
    if(n<=1)
    {
    mem[n]=n;
    return n;
    }

    if(mem[n]!=0)
    {
    return mem[n];
    }
    long long int ans=fibonacci_02(n-1,mem)+fibonacci_02(n-2,mem);
    
    mem[n]=ans;
    return ans; 

}

int fibonacci_03(int n,vector<int>& mem) //fibonacci
{
    for(int i=0;i<=n;i++)
    {
        if(i<=1)
        {
        mem[i]=i;
        continue;
        }
        mem[i]=mem[i-1]+mem[i-2];
        
    }
    return mem[n];
}


int mazepath_02(int sr,int sc,int er,int ec,vector<vector<int>>& dp)
{
    if(sr==er && sc==ec)
    { dp[sr][sc]=1;
     return 1;
    }

    int count=0;
    if(dp[sr][sc]!=0)return dp[sr][sc];
    //if(er==ec && dp[sc][sr]!=0) return dp[sc][sr];
    if(sr+1<=er)
    count+=mazepath_02(sr+1,sc,er,ec,dp);
    if(sc+1<=ec)
    count+=mazepath_02(sr,sc+1,er,ec,dp);
    dp[sr][sc]=count;
    if(er==ec)
    dp[sc][sr]=count;

    return count;
}


int mazepathHV_03(int er,int ec,vector<vector<int>>& dp)
{
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
            if(sr==er && sc==ec)
            { dp[sr][sc]=1;
            continue;
            }

            int count=0;
            
            if(sr+1<=er)
            count+=dp[sr+1][sc];
            if(sc+1<=ec)
            count+=dp[sr][sc+1];
            dp[sr][sc]=count;
           

        }
    }
    return dp[0][0];
}

int mazepathHVD_03(int er,int ec,vector<vector<int>>& dp)
{
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
            if(sr==er && sc==ec)
            { dp[sr][sc]=1;
            continue;
            }

            int count=0;
            
            if(sr+1<=er)
            count+=dp[sr+1][sc];
            if(sc+1<=ec)
            count+=dp[sr][sc+1];
            if(sr+1<=er && sc+1<=ec)
            count+=dp[sr+1][sc+1];
            dp[sr][sc]=count;
           

        }
    }
    return dp[0][0];
}

//memoization
int tileFloor(int n,int m,vector<int>& dp)
{
    if(n<=m){
    dp[n]= (m==n)?2:1;
    return dp[n];
    }
    if(dp[n]!=0)return dp[n];
    int horizontal=tileFloor(n-1,m,dp);
    int vertical=tileFloor(n-m,m,dp);
    dp[n]=horizontal+vertical;
    return dp[n];

}
//tabulation

int tileFloor_02(int n,int m,vector<int>& dp) //O(n space)
{

for(int i=0;i<=n;i++)
{
    if(i<=m){
    dp[i]=(m==i)?2:1;
    continue;
    }
    
    int horizontal=dp[i-1];
    int vertical=dp[i-m];
    dp[i]=horizontal+vertical;
}
    return dp[n];

}
//space optimization.
int tileFloor_03(int n,int m) //O(m) space
{
    if(n<=m)
    return ((m==n)?2:1);  //if n<=m linked is not made directly ans
                        //is calculated in o(1) time O(1) space. 
    list<int> l1;
    for(int i=1;i<=m;i++)
    {
        l1.push_back(1);
    }
    for(int i=m;i<=n;i++)
    {
        
        int horizontal=l1.back();
        int vertical=l1.front();
        l1.push_back(horizontal+vertical);
        l1.pop_front();
    }
    return l1.back();

}
void display(vector<int>& dp)
{
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }

    cout<<endl;
}
void set2()
{ 
    int n=17;int m=6;
    vector<int> mem2(n+1,0);
    // cout<<tileFloor(17,6,mem2)<<endl;
    // display(mem2);
    // cout<<tileFloor_02(17,6,mem2)<<endl;
    // display(mem2);
    cout<<tileFloor_03(17,6);
}
int main(int a,char** b)
{
    // int n=10;
    // vector<int> mem(n+1,0);
    // vector<vector<int>> dp(3,vector<int>(3,0));

    // //cout<<fibonacci(n);
    // //cout<<fibonacci_02(n,mem);
    // //cout<<fibonacci_03(n,mem);
    // cout<<mazepath_02(0,0,2,2,dp);
    set2();
    
}