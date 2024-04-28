class Solution {
public:
    int f(vector<vector<int>>&dp,vector<int>&rods,int idx,int diff)
    {
        if(idx>=rods.size())
        {
            if(diff==0) return 0;
            else return INT_MIN;
        }
        if(dp[idx][diff+5001]!=-1) return dp[idx][diff+5001];
        int op1=f(dp,rods,idx+1,diff+rods[idx]);
        int op2=rods[idx]+f(dp,rods,idx+1,diff-rods[idx]);
        int op3=f(dp,rods,idx+1,diff);
        return dp[idx][diff+5001]=max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(21,vector<int>(10002,-1));
        return f(dp,rods,0,0);
    }
};