class Solution {
public:
    int f(vector<vector<vector<int>>>&dp,vector<int>&prices,int k,int i,int buy,int n)
    {
        if(k<=0) return 0;
        if(i==n) return 0;
        
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy==0)
        {
            return dp[i][buy][k]=max(f(dp,prices,k,i+1,0,n),f(dp,prices,k,i+1,1,n)-prices[i]);
        }
        else return dp[i][buy][k]=max(f(dp,prices,k-1,i+1,0,n)+prices[i],f(dp,prices,k,i+1,1,n));

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(dp,prices,2,0,0,n);
    }
};