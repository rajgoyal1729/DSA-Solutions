class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9];
        unordered_set<char>col[9];
        unordered_set<char>box[9];

        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                char val= board[r][c];
                if(val=='.') continue;
                cout<<val;
                if(row[r].count(val)) return false;
                 row[r].insert(val);

                if(col[c].count(val)) return false;
                 col[c].insert(val);

                int index= (r/3)*3 + (c/3);
                if(box[index].count(val)) return false;
                 box[index].insert(val);
            }
        }
        return true;
    }
};