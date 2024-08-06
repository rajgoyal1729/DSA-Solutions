class Solution {
public:
    int f(vector<int>&dp, string s, int i)
    {
        if(i>=s.size()) return 1;
        if(s[i]=='0') return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
        int ans=f(dp,s,i+1);
        if(i<s.size()-1&& (s[i]=='1' || s[i]=='2' && s[i+1]<'7')) ans+=f(dp,s,i+2);
        return dp[i]=ans;

    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int>dp(s.size()+1,-1);
        return f(dp,s,0);

    }
};