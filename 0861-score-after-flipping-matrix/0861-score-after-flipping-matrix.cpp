class Solution {
public:
    void flipCol(vector<vector<int>>&grid, int row, int col)
    {
        for(int i=0;i<row;i++)
        {
            if(grid[i][col]==0) grid[i][col]=1;
            else grid[i][col]=0;
        }
    }
    void flipRow(vector<vector<int>>&grid, int row,int col)
    {
        for(int i=0;i<col;i++)
        {
            if(grid[row][i]==0) grid[row][i]=1;
            else grid[row][i]=0;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            if(grid[i][0]==0) flipRow(grid,i,col);
        }
        for(int j=0;j<col;j++)
        {
            int count=0;
            for(int i=0;i<row;i++)
            {
                if(grid[i][j]==1) count++;
            }
            if(count<=row/2) flipCol(grid,row,j);
        }
        for(int i=0;i<row;i++)
        {
            int sum=0;
            for(int j=col-1;j>=0;j--)
            {
                sum+=grid[i][j]*pow(2,col-1-j);
            }
            ans+=sum;
        }
        return ans;
        
    }
};