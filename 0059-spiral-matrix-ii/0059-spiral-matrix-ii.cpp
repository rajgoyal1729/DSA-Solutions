class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int x=1;
        int ri=0,ci=0;
        int re=n,ce=n;
        while(x<=n*n && ri<re && ci<ce)
        {
            for(int i=ci;i<ce;i++)
            {ans[ri][i]=x;
            x++;}
            ri++;

            for(int i=ri;i<re;i++)
            {
                ans[i][ce-1]=x;
                x++;
            }
            ce--;

            if(ri<re)
            {
                for(int i=ce-1;i>=ci;i--)
                {
                    ans[re-1][i]=x;
                    x++;
                }
                re--;
            }
            if(ci<ce)
            {
                for(int i=re-1;i>=ri;i--)
                {
                    ans[i][ci]=x;
                    x++;
                }
                ci++;
            }
        }
        return ans;

    }
};