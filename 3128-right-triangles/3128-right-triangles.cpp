class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>rowV(row);
        vector<int>colV(col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    rowV[i]++;
                    colV[j]++;
                }
            }
        }
        long long count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    count+=(rowV[i]-1)*(colV[j]-1);
                }
            }
        }
        return count;
        
    }
};