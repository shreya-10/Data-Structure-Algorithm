#include<iostream>
#include<vector>
using namespace std;

//recursive
int bPath(vector<int> &dp,int st,int end)
{
    if(st==end)
    return 1;
    int count=0;
    for(int i=1;i<=6;i++)
    {
        if(st+i<=end)
        count+=bPath(dp,st+i,end);

    }
    return count;

}
//memoization
int bPath_02(vector<int> &dp,int st,int end)
{
    if(st==end)
    {
        dp[st]=1;
        return dp[st];
    }
    int count=0;
    if(dp[st]!=0) return dp[st];
    for(int dice=1;dice<=6 && st+dice<=end;dice++)
    {
     
     count+=bPath_02(dp,st+dice,end);
     
    }
    dp[st]=count;
    return count;

}

//tabulation
int bPath_03(vector<int> &dp,int st,int end)
{
    for(int i=end;i>=0;i--)
    {
    if(i==end)
    {
        dp[i]=1;
        continue;
    }
    int count=0;
    for(int dice=1;dice<=6 && i+dice<=end;dice++)
    {
     
     count+=dp[i+dice];
     
    }
    dp[i]=count;
    }
    return dp[0];

}

int bPathRandom(vector<int>& dp,int st,int end,vector<int>& arr)
{
    if(st==end)
    {
        dp[st]=1;
        return 1;
    }
    int count=0;

    if(dp[st]!=0)return dp[st];
    for(int i=0;i<arr.size();i++)
    {
        if(st+arr[i]<=end)
        {
            count+=bPathRandom(dp,st+arr[i],end,arr);
        }
    }
    dp[st]=count;
    return count;
}
//tabulation
int bPathRandom_02(vector<int>& dp,int st,int end,vector<int>& arr)
{
    for(int i=end;i>=0;i--)
    {
    if(i==end)
    {
        dp[i]=1;
        continue;
    }
    int count=0;

   
    for(int itr=0;itr<arr.size();itr++)
    {
        if(i+arr[itr]<=end)
        {
            count+=dp[i+arr[itr]];
        }
    }
    dp[i]=count;
    }
    return dp[0];
}
void display(vector<int>& dp)
{
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }

    cout<<endl;
}
void set1()
{
     int n=4;
    vector<int> dp(n+1,0);
    //cout<<bPath(dp,0,n)<<endl;
    // cout<<bPath_02(dp,0,n)<<endl;
    //cout<<bPath_03(dp,0,n)<<endl;
    display(dp);
}
void set2()
{
     int n=10;
    vector<int> dp(n+1,0);
    vector<int> arr={2,3,5,7};
    ///cout<<bPathRandom(dp,0,n,arr)<<endl;
    cout<<bPathRandom_02(dp,0,n,arr)<<endl;
    display(dp);


}
int main(int a,char** b)
{
    set2();
   
}