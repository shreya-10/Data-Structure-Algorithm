#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<int>>& dp)
{
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        cout<<dp[i][j]<<" ";
        
        cout<<endl;
    }

    
}

int setpart(int n,int k)
{
    if(n==k || k==1)
    return 1;
    int count=0;
    int newSet=setpart(n-1,k-1);
    int partOfSet=setpart(n-1,k)*k;

    count+=newSet+partOfSet;
    return  count;
}

int setpart_02(int n,int k,vector<vector<int>> dp)
{
    if(n<k)
    {
    dp[n][k]=0;
    return 0;
    }
    if(n==k || k==1)
    {dp[n][k]=1;
    return 1;
    }
    int count=0;
    if(dp[n][k]!=0)return dp[n][k];
    int newSet=setpart_02(n-1,k-1,dp);
    int partOfSet=setpart_02(n-1,k,dp)*k;

    count+=newSet+partOfSet;
    dp[n][k]=count;
    return  count;
}

int setpart_03(int n,int k,vector<vector<int>>&+ dp)
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    {
    if(i<j)
    {
    dp[i][j]=0;
    continue;
    }
    if(i==j || j==1)
    {dp[i][j]=1;
    continue;
    }
    
    
    int newSet=dp[i-1][j-1];
    int partOfSet=dp[i-1][j]*j;

    
    dp[i][j]=newSet+partOfSet;
    }
    
    return  dp[n][k];
}

int main(int args,char** argb)
{
    int n=5;
    int k=3;
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    //cout<<setpart_02(5,3,dp)<<endl;
    cout<<setpart_03(5,3,dp)<<endl;
    display(dp);
}