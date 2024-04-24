class Solution {
public:
    int f(vector<vector<int>>&dp,vector<int>&prices,int n,int i,int buy)
    {
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0)
        {
            return dp[i][buy]=max(f(dp,prices,n,i+1,0),f(dp,prices,n,i+1,1)-prices[i]);
        }
        else return dp[i][buy]=max(f(dp,prices,n,i+1,0)+prices[i],f(dp,prices,n,i+1,1));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(dp,prices,n,0,0);
    }
};