class Solution {
public:
   /* int f(int n,vector<int>&dp)
    {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=0) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }*/
    int climbStairs(int n) {
        /*vector<int>dp(n+1,0);
        return f(n,dp);*/
        vector<int>dp(n+1,0);
        if(n==1) return 1;
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};