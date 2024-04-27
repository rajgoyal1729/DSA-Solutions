class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        bool flag=false;
        int W=0,B=0;
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                if(grid[i][j]=='W') W++;
                else B++;
            }
        }
        if(abs(W-B)==2 || W==0 || B==0) flag=true;
        W=0,B=0;
        
        for(int i=0;i<=1;i++)
        {
            for(int j=1;j<=2;j++)
            {
                if(grid[i][j]=='W') W++;
                else B++;
            }
        }
        if(abs(W-B)==2 || W==0 || B==0) flag=true;
        W=0,B=0;
        
        for(int i=1;i<=2;i++)
        {
            for(int j=0;j<=1;j++)
            {
                if(grid[i][j]=='W') W++;
                else B++;
            }
        }
        if(abs(W-B)==2 || W==0 || B==0) flag=true;
        W=0,B=0;
        
        for(int i=1;i<=2;i++)
        {
            for(int j=1;j<=2;j++)
            {
                if(grid[i][j]=='W') W++;
                else B++;
            }
        }
        if(abs(W-B)==2 || W==0 || B==0) flag=true;
        W=0,B=0;
        return flag;
    }
};