class Solution {
public:
    int f(vector<vector<int>>&dp, int n,int k,int target)
    {
        if(n==0 && target==0) return 1;
        if(n==0 || target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ways=0;
        for(int i=1;i<=k;i++)
        {
            ways= (ways+ f(dp,n-1,k,target-i))% 1000000007;

        } 
        
        return dp[n][target]= ways % 1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(dp,n,k,target);
    }
};