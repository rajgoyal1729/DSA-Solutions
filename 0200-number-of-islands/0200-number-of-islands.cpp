class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i,int j)
    {
        int row=grid.size();int col=grid[0].size();
        if(i<0 || j<0 || i>=row || j>=col) return ;
        if(grid[i][j]=='2' || grid[i][j]=='0') return;
        grid[i][j]='2';
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};