#include<iostream>
#include<vector>
using namespace std;

//recursion
int permutation(vector<int>& coins,int tar,vector<int>& dp)
{
    if(tar==0)
    return 1;

    int count=0;
    for(int i=0;i<coins.size();i++)
    {
        if(tar-coins[i]>=0)
        count+=permutation(coins,tar-coins[i],dp);
    }
    return count;
}

//memoization
int permutation_02(vector<int>& coins,int tar,vector<int>& dp)
{
    if(tar==0)
    {
        dp[tar]=1;
        return 1;
    }

    int count=0;

    if(dp[tar]!=0)return dp[tar];
    for(int i=0;i<coins.size();i++)
    {
        if(tar-coins[i]>=0)
        count+=permutation_02(coins,tar-coins[i],dp);
    }
    dp[tar]=count;
    return count;
}

int permutationDP_03(vector<int>& coins,int tar,vector<int>& dp)
{
    dp[0]=1;
    for(int t=1;t<=tar;t++)
    
    {
        int count=0;

      
        for(int i=0;i<coins.size();i++)
        {
            if(t-coins[i]>=0)
            count+=dp[t-coins[i]];
        }
        dp[t]=count;
    }
    return dp[tar];
}
void display(vector<int>& dp)
{
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }

    cout<<endl;
}

int main(int arg,char** argb)
{
    int tar=10;
    vector<int> coins{2,3,5,7};
    vector<int> dp(tar+1,0);
    // cout<<permutation(coins,tar,dp);
    cout<<permutationDP_03(coins,tar,dp)<<endl;
    display(dp);

}