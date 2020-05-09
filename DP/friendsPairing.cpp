#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& dp)
{
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }

    cout<<endl;
}
int friendsPair(int n)
{
    if(n==2)
    return 2;//two ways :pair up or single
    if(n==1)
    return 1;//only one way :single

    int single=friendsPair(n-1);
    int pairUp=friendsPair(n-2)*(n-1);
    int totalWays=single+pairUp;
    return totalWays;
}

int friendsPair_02(int n,vector<int>& dp)
{
    
    if(n<=1)
    {
    dp[n]=1;
    return 1;
    }
    
    if(dp[n]!=0)return dp[n];
    int single=friendsPair_02(n-1,dp);
    int pairUp=friendsPair_02(n-2,dp)*(n-1);
    dp[n]=single+pairUp;
    return dp[n];
}

int friendsPair_03(int n,vector<int>& dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i<=1)
        {
        dp[i]=1;
        continue;
        }
    dp[i]=dp[i-1]+(i-1)*dp[i-2];
    
    }
    return dp[n];
}
int friendsPair_04(int n)
{
    int a=1,b=1;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
      ans=a*(i-1)+b;
        a=b;
        b=ans;
    }
    return ans;
}

int main(int args,char** argb)
{
    int n=6;
    vector<int> dp(n+1);
    cout<<friendsPair_04(n)<<endl;
    display(dp);
}