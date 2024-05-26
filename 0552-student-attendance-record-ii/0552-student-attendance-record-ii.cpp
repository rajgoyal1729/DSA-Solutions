class Solution {
public:
    long long mod= 1000000007;
    int f(vector<vector<vector<int>>>&dp,int n, int totalA, int totalL)
    {
        if(totalA>=2 || totalL>=3) return 0;
        if(n==0) return 1;
        if(dp[n][totalA][totalL]!=-1) return dp[n][totalA][totalL];
        int count=0;
        count= f(dp,n-1,totalA,0);
        count=(count+f(dp,n-1,totalA+1,0))%mod;
        count=(count+f(dp,n-1,totalA,totalL+1))%mod;

        return dp[n][totalA][totalL]=count;
    }
    int checkRecord(int n) {
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(dp,n,0,0);            
    }
};