class Solution {
public:
    int f(vector<vector<int>>&dp,string &s,int k, int i, int prev_i)
    {
        if(i>=s.length()) return 0;
        if(dp[i][prev_i]!=-1) return dp[i][prev_i];
        int ans=0;
        if(prev_i==0 ||abs(s[i]-prev_i)<=k) ans=1+f(dp,s,k,i+1,s[i]);
         ans=max(ans,f(dp,s,k,i+1,prev_i));
        return dp[i][prev_i]=ans;
    }
    int longestIdealString(string s, int k) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(150,-1));
        return f(dp,s,k,0,0);
    }
};