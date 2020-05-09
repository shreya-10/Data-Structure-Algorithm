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

int Min_jump(int idx,vector<int>& nums)
{
    if(nums.size()-1==idx)
    return 0;

    // if(arr[idx]==0)
    // return (int)1e7;

    int minAns=(int)1e7;
    for(int jump=1;jump<=nums[idx] && idx+jump<nums.size();jump++)
    {
        int recans=Min_jump(idx+jump,nums);
        if(recans!=(int)1e7 && recans+1<minAns)
        minAns=recans+1;

    }
    return minAns;
    }

int Min_jump_02(int idx,vector<int>& nums,vector<int>& dp)
{
    if(nums.size()-1==idx)
    {
      dp[idx]=0;
      return 0;
    }

    // if(arr[idx]==0)
    // return (int)1e7;
    if(dp[idx]!=0) return dp[idx];
    int minAns=(int)1e7;
    for(int jump=1;jump<=nums[idx] && idx+jump<nums.size();jump++)
    {
        int recans=Min_jump(idx+jump,nums);
        if(recans!=(int)1e7 && recans+1<minAns)
        minAns=recans+1;

    }
    dp[idx]=minAns;
    return minAns;
    }

    int Min_jump_03(int idx,vector<int>& nums,vector<int>& dp)
{
    int n=nums.size();
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
    int minAns=(int)1e7;
    for(int jump=1;jump<=nums[idx] && i+jump<nums.size();jump++)
    {
        int recans=dp[i+jump];
        if(recans!=(int)1e7 && recans+1<minAns)
       minAns=recans+1;

    }
   dp[i]=minAns;
    }
    return dp[0];
    }
    

int main(int args,char** argb)
{
    vector<int> nums{4,3,5,1,0,3,2,1,2,2,1};
    vector<int> dp(nums.size()+1);
    // cout<<Min_jump(0,nums);
    //cout<<Min_jump_02(0,nums,dp)<<endl;
    //display(dp);
    cout<<Min_jump_03(0,nums,dp)<<endl;
}