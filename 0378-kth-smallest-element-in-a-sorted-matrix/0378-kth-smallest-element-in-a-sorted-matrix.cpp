class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=matrix[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //pq.push(matrix[0][0],0,0);
        for(int i=0;i<min(row,k);i++)
        {
            pq.push({matrix[i][0],i,0});
        }
        for(int i=1;i<=k;i++)
        {
            auto top=pq.top();
            pq.pop();
             ans=top[0];
            int r=top[1];
            int c=top[2];
            if(c<col-1) pq.push({matrix[r][c+1],r,c+1});
        }
        return ans;
        
    }
};