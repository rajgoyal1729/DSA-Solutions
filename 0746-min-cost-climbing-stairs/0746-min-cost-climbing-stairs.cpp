class Solution {
public:
    int f(vector<int>&dp,int n,vector<int>&cost)
    {
        if(n<=1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n]=min(f(dp,n-1,cost),f(dp,n-2,cost))+cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(dp,n-1,cost),f(dp,n-2,cost));
    };
};