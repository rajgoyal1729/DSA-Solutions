class Solution {
public:
    int f(vector<vector<int>>&dp,int i,int j)
    {
        if(i==0&&j==0) return 1;
        if(i<0 || j<0) 
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int top=f(dp,i-1,j);
        int left=f(dp,i,j-1);
        return dp[i][j]=top+left; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(dp,m-1,n-1);
    }
};