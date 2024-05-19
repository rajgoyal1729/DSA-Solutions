class Solution {
public:
    int f(vector<vector<int>>&dp,vector<vector<int>>&grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int rowTake=INT_MIN, colTake=INT_MIN;
        if(i<grid.size()-1)rowTake=grid[i+1][j]-grid[i][j]+f(dp,grid,i+1,j);
        if(j<grid[0].size()-1)colTake=grid[i][j+1]-grid[i][j]+f(dp,grid,i,j+1);
        return dp[i][j]=max(0,max(colTake,rowTake));
    }
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<m-1) ans=max(ans,grid[i+1][j]-grid[i][j]+f(dp,grid,i+1,j));
                 if(j<n-1) ans=max(ans,grid[i][j+1]-grid[i][j]+f(dp,grid,i,j+1));               
            }
        }
        return ans;
    }
};