class Solution {
public:
    vector<int>directions={0,1,0,-1,0};
    int dfs(vector<vector<int>>&grid, int row, int col, int i, int j)
    {
        if(i>=row || j>=col || i<0 || j<0 || grid[i][j]==0)
        return 0;
        int maxGold=0;
        int val=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            maxGold=max(maxGold,dfs(grid,row,col,directions[k]+i,directions[k+1]+j));
        }
        grid[i][j]=val;
        return maxGold+val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int maxGold=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]!=0)
                maxGold=max(maxGold,dfs(grid,row,col,i,j));
            }
        }
        return maxGold;
    }
};