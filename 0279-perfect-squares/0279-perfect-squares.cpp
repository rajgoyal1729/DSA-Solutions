class Solution {
public:
    
    int numSquares(int n) {
        vector<int>v;
        if(n==1) return 1;
        for(int i=1;i<=n/2;i++)
        {
            if(i*i<=n) v.push_back(i*i);
        }
        int size=v.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<size;i++)
        {
            for(int j=v[i];j<=n;j++)
            dp[j]=min(dp[j],dp[j-v[i]]+1);
        }
        return dp[n];
    }
};