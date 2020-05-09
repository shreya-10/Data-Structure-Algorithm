class Solution {
public:

//memoization
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n=cost.size()-1;
        vector<int> dp(n+1,0);
        return minCost(n,dp,cost);
    }
    int minCost(int n,vector<int>& dp,vector<int>& cost)
    {
        if(n<=1)
            return cost[n];
        if(dp[n]!=0)
            return dp[n];
        int c1=minCost(n-1,dp,cost);
        int c2=minCost(n-2,dp,cost);
        dp[n]=min(c1,c2)+cost[n];
        
        return dp[n];
    }
    //TABULATION
     int minCost(int n,vector<int>& dp,vector<int>& cost)
    {
        for(int i=0;i<=n;i++)
        {
        if(i<=1)
        {
            dp[i]=cost[i];
            continue;
        }
        
        int c1=dp[i-1];
        int c2=dp[i-2];
        dp[i]=min(c1,c2)+cost[i];
        }
        
        return dp[n];
    }
};