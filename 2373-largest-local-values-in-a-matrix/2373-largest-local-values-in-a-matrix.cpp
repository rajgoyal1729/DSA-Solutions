class Solution {
public:
    int f(vector<vector<int>>&grid, int rowEnd, int colEnd, int rowStart, int colStart)
    {
        int ans=INT_MIN;
        for(int i=rowStart;i<=rowEnd;i++)
        {
            for(int j=colStart;j<=colEnd;j++)
            ans=max(ans,grid[i][j]);
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>ans(row-2,vector<int>(col-2,-1));
        for(int i=0;i<row-2;i++)
        {
            for(int j=0;j<col-2;j++)
            {
                ans[i][j]=max(ans[i][j], f(grid,i+2,j+2,i,j));
            }
        }
        return ans;
    }
};