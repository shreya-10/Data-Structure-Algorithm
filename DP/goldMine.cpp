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
vector<vector<int>> dir={{0,1},{-1,1},{1,1}};
int goldMine(int x,int y,vector<vector<int>>& dp,vector<vector<int>>& arr)
{
 if(y==arr[0].size()-1)
 {
     dp[x][y ]= arr[x][y];
    return arr[x][y];
 }
  if (dp[x][y] != 0)
        return dp[x][y];

 int maxans=-1e7;
 for(int d=0;d<3;d++)
 {
     int r=x+dir[d][0];
     int c=y+dir[d][1];
  if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
    maxans=max(goldMine(r,c,dp,arr),maxans);
 }

 dp[x][y]= maxans+arr[x][y];
  return dp[x][y];
 

}

int goldMine_02(vector<vector<int>>& dp,vector<vector<int>>& arr)
{
    for(int y=arr[0].size()-1;y>=0;y--)
    {
        for(int x=arr.size()-1;x>=0;x--)
        {
                if(y==arr[0].size()-1)
                {
                    dp[x][y ]= arr[x][y];
                    continue;
                }
                int maxans=-1e7;
                for(int d=0;d<3;d++)
                {
                    int r=x+dir[d][0];
                    int c=y+dir[d][1];
                if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
                    maxans=max(dp[r][c],maxans);
                }

                dp[x][y]= maxans+arr[x][y];
               
 
        }
    }
    int maxAns = -1e6;
    for (int row = 0; row < arr.size(); row++)
    {
        maxAns = max(maxAns, dp[row][0]);
    }

     return maxAns;
 
 
 

}

int main(int args,char** argb)
{
    
    vector<vector<int>> arr{
        {1,3,3},
        {2,1,4},
        {0,6,4}
    };
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));

     int ans=-1e7;
//     for(int row=0;row<arr.size();row++)
//     {
//      ans =max(goldMine(row,0,dp,arr),ans);
//     }
//   cout<<ans;

cout<<goldMine_02(dp,arr)<<endl;
display(dp);
}