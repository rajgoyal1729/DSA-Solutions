class Solution {
public:
    bool isMax(vector<vector<int>>&matrix, int col,int mini)
    {
        int row=matrix.size();
        int maxi=INT_MIN;
        for(int i=0;i<row;i++)
        {
            maxi=max(maxi,matrix[i][col]);
        }
        return maxi==mini;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            int mini=INT_MAX;
        int idx;
            for(int j=0;j<col;j++)
            {
                if(mini>matrix[i][j])
                {
                    mini=matrix[i][j];
                    idx=j;
                }
            }
            
            if(isMax(matrix,idx,mini)) ans.push_back(matrix[i][idx]);
        }
        return ans;
    }
};