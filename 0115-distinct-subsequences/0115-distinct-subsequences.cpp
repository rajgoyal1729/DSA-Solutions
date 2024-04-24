class Solution {
public:
    int f(vector<vector<int>>&dp,string &s, string &t,int i,int j)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f(dp,s,t,i-1,j-1)+f(dp,s,t,i-1,j);
        else return dp[i][j]=f(dp,s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int i=s.length();
        int j=t.length();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(dp,s,t,i-1,j-1);
    }
};