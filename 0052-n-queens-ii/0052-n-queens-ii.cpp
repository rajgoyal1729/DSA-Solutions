class Solution {
public:
    bool isSafe(vector<string>&board, int row, int col)
    {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            if(board[i][col]=='Q') return false;
            if(row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q') return false;
            if(row-i>=0 && col+i<n && board[row-i][col+i]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string>&board, int& ans, int row)
    {
        if(row==board.size())
        {
            ans++;
            return ;
        }
        for(int i=0;i<board.size();i++)
        {
            if(isSafe(board,row,i))
            {
                board[row][i]='Q';
                solve(board,ans,row+1);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string>board(n,string(n,'.'));
        solve(board,ans,0);
        return ans;
    }
};