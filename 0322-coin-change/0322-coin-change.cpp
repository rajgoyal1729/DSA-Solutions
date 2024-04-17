class Solution {
public:
    int f(vector<int>&dp,int amount,vector<int>&coins)
    {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int mini=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            mini=f(dp,amount-coins[i],coins);
            if(mini!=INT_MAX) ans=min(mini+1,ans);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=f(dp,amount,coins);
        return ans==INT_MAX?-1:ans;
    }
};